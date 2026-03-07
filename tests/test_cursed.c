#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#ifndef TARGET_BINARY
#define TARGET_BINARY "./build/cursed_spawn"
#endif

#define OUTPUT_CAPACITY 8192
#define COMMAND_TIMEOUT_MS 3000

typedef struct {
    unsigned char output[OUTPUT_CAPACITY];
    size_t output_len;
    int exit_code;
    int timed_out;
} CommandResult;

static long long monotonic_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000LL + ts.tv_nsec / 1000000LL;
}

static void append_output(CommandResult *result, const unsigned char *chunk, size_t chunk_len) {
    size_t space = OUTPUT_CAPACITY - 1 - result->output_len;
    size_t copy_len = chunk_len < space ? chunk_len : space;

    if (copy_len > 0) {
        memcpy(result->output + result->output_len, chunk, copy_len);
        result->output_len += copy_len;
    }

    result->output[result->output_len] = '\0';
}

static void set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags >= 0) {
        (void)fcntl(fd, F_SETFL, flags | O_NONBLOCK);
    }
}

static int run_command(char *const argv[], CommandResult *result) {
    int pipefd[2];
    pid_t pid;
    int status = 0;
    int child_exited = 0;
    int pipe_open = 1;
    long long deadline = monotonic_ms() + COMMAND_TIMEOUT_MS;

    memset(result, 0, sizeof(*result));
    result->exit_code = -1;

    if (pipe(pipefd) != 0) {
        perror("pipe");
        return -1;
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        close(pipefd[0]);
        close(pipefd[1]);
        return -1;
    }

    if (pid == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        dup2(pipefd[1], STDERR_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execv(TARGET_BINARY, argv);
        perror("execv");
        _exit(127);
    }

    close(pipefd[1]);
    set_nonblocking(pipefd[0]);

    while (pipe_open || !child_exited) {
        struct pollfd pollfd = {
            .fd = pipefd[0],
            .events = POLLIN | POLLHUP,
            .revents = 0,
        };
        long long remaining_ms = deadline - monotonic_ms();
        int timeout_ms = 100;

        if (!result->timed_out && remaining_ms < timeout_ms) {
            timeout_ms = remaining_ms > 0 ? (int)remaining_ms : 0;
        }

        if (!pipe_open) {
            timeout_ms = timeout_ms > 25 ? 25 : timeout_ms;
        }

        if (pipe_open) {
            int poll_status = poll(&pollfd, 1, timeout_ms);
            if (poll_status > 0 && (pollfd.revents & (POLLIN | POLLHUP))) {
                unsigned char buffer[1024];

                for (;;) {
                    ssize_t bytes_read = read(pipefd[0], buffer, sizeof(buffer));
                    if (bytes_read > 0) {
                        append_output(result, buffer, (size_t)bytes_read);
                    } else if (bytes_read == 0) {
                        close(pipefd[0]);
                        pipe_open = 0;
                        break;
                    } else if (errno == EAGAIN || errno == EWOULDBLOCK) {
                        break;
                    } else {
                        close(pipefd[0]);
                        pipe_open = 0;
                        break;
                    }
                }
            }
        } else {
            (void)poll(NULL, 0, timeout_ms);
        }

        if (!child_exited) {
            pid_t wait_status = waitpid(pid, &status, WNOHANG);
            if (wait_status == pid) {
                child_exited = 1;
            } else if (wait_status < 0) {
                perror("waitpid");
                return -1;
            }
        }

        if (!result->timed_out && monotonic_ms() >= deadline && !child_exited) {
            result->timed_out = 1;
            (void)kill(pid, SIGKILL);
        }
    }

    if (WIFEXITED(status)) {
        result->exit_code = WEXITSTATUS(status);
    } else if (WIFSIGNALED(status)) {
        result->exit_code = 128 + WTERMSIG(status);
    }

    return 0;
}

static int output_contains(const CommandResult *result, const char *needle) {
    return strstr((const char *)result->output, needle) != NULL;
}

static int output_equals(const CommandResult *result, const unsigned char *expected, size_t expected_len) {
    return result->output_len == expected_len && memcmp(result->output, expected, expected_len) == 0;
}

static void report_result(const char *name, int passed, int *tests_run, int *tests_passed) {
    printf("Running test: %s... %s\n", name, passed ? "PASSED" : "FAILED");
    (*tests_run)++;
    if (passed) {
        (*tests_passed)++;
    }
}

int main(void) {
    int tests_run = 0;
    int tests_passed = 0;
    CommandResult result;

    static const unsigned char dimension_zero_output[] = "oW olleH\n!dlr";
    static const unsigned char dimension_one_output[] = {
        0x5d, 0x08, 0x48, 0x7d, 0x08, 0x65, 0x64, 0x08, 0x6c, 0x69,
        0x08, 0x6c, 0x62, 0x08, 0x6f, 0x32, 0x08, 0x20, 0x48, 0x08,
        0x57, 0x7e, 0x08, 0x6f, 0x62, 0x08, 0x72, 0x6d, 0x08, 0x6c,
        0x75, 0x08, 0x64, 0x33, 0x08, 0x21, 0x09, 0x08, 0x0a,
    };
    static const unsigned char dimension_two_output[] = {
        0x57, 0x20, 0x6f, 0x6c, 0x6c, 0x65, 0x48, 0x00, 0x0a, 0x21, 0x64, 0x6c, 0x72,
    };
    static const unsigned char quantum_output[] = {
        0x43, 0x08, 0x48, 0x68, 0x08, 0x65, 0x60, 0x08, 0x6c, 0x63,
        0x08, 0x6c, 0x60, 0x08, 0x6f, 0xd1, 0x08, 0x20, 0xa5, 0x08,
        0x57, 0x9a, 0x08, 0x6f, 0x86, 0x08, 0x72, 0x98, 0x08, 0x6c,
        0x9f, 0x08, 0x64, 0xdc, 0x08, 0x21, 0xf5, 0x08, 0x0a,
    };
    static const unsigned char repeat_dimension_zero_output[] =
        "=== RITUAL 1/2 ===\n"
        "oW olleH\n!dlr\n"
        "=== RITUAL 2/2 ===\n"
        "oW olleH\n!dlr";
    static const unsigned char help_prefix[] = "CURSED HELLO WORLD FROM THE DEPTHS OF PROGRAMMING HELL";
    static const unsigned char version_prefix[] = "Hello World From Hell v2.0 - Cursed Edition";
    static const unsigned char dimension_three_prefix[] = "Hello World!\n";

    printf("Starting Cursed Test Suite...\n");

    {
        char *const argv[] = {TARGET_BINARY, "--help", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code == 0 &&
                     output_contains(&result, (const char *)help_prefix) &&
                     output_contains(&result, "Usage: ./cursed_spawn [OPTIONS]") &&
                     output_contains(&result, "DIMENSIONS:");
        report_result("Help output is available", passed, &tests_run, &tests_passed);
    }

    {
        char *const argv[] = {TARGET_BINARY, "--version", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code == 0 &&
                     output_contains(&result, (const char *)version_prefix) &&
                     output_contains(&result, "Architecture:");
        report_result("Version output is available", passed, &tests_run, &tests_passed);
    }

    {
        char *const argv[] = {TARGET_BINARY, "-d", "0", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code >= 0 &&
                     result.exit_code < 128 &&
                     output_equals(&result, dimension_zero_output, sizeof(dimension_zero_output) - 1);
        report_result("Dimension 0 stays deterministic", passed, &tests_run, &tests_passed);
    }

    {
        char *const argv[] = {TARGET_BINARY, "-d", "1", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code >= 0 &&
                     result.exit_code < 128 &&
                     output_equals(&result, dimension_one_output, sizeof(dimension_one_output));
        report_result("Dimension 1 stays deterministic", passed, &tests_run, &tests_passed);
    }

    {
        char *const argv[] = {TARGET_BINARY, "-d", "2", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code >= 0 &&
                     result.exit_code < 128 &&
                     output_equals(&result, dimension_two_output, sizeof(dimension_two_output));
        report_result("Dimension 2 keeps its embedded NUL weirdness", passed, &tests_run, &tests_passed);
    }

    {
        char *const argv[] = {TARGET_BINARY, "-d", "3", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code >= 0 &&
                     result.exit_code < 128 &&
                     result.output_len >= sizeof(dimension_three_prefix) &&
                     memcmp(result.output, dimension_three_prefix, sizeof(dimension_three_prefix) - 1) == 0 &&
                     result.output[sizeof(dimension_three_prefix) - 1] == '\0';
        report_result("Dimension 3 still begins with Hello World", passed, &tests_run, &tests_passed);
    }

    {
        char *const argv[] = {TARGET_BINARY, "-d", "8", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code >= 0 &&
                     result.exit_code < 128 &&
                     output_equals(&result, dimension_zero_output, sizeof(dimension_zero_output) - 1);
        report_result("Dimension values still wrap sanely", passed, &tests_run, &tests_passed);
    }

    {
        char *const argv[] = {TARGET_BINARY, "-r", "0", "-d", "0", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code >= 0 &&
                     result.exit_code < 128 &&
                     output_equals(&result, dimension_zero_output, sizeof(dimension_zero_output) - 1);
        report_result("Repeat count clamps at one", passed, &tests_run, &tests_passed);
    }

    {
        char *const argv[] = {TARGET_BINARY, "-r", "2", "-d", "0", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code >= 0 &&
                     result.exit_code < 128 &&
                     output_equals(&result, repeat_dimension_zero_output, sizeof(repeat_dimension_zero_output) - 1);
        report_result("Repeated rituals stay reproducible", passed, &tests_run, &tests_passed);
    }

    {
        char *const argv[] = {TARGET_BINARY, "-d", "7", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code >= 0 &&
                     result.exit_code < 128 &&
                     output_equals(&result, quantum_output, sizeof(quantum_output));
        report_result("Quantum mode remains deterministic enough to test", passed, &tests_run, &tests_passed);
    }

    {
        char *const argv[] = {TARGET_BINARY, "-t", NULL};
        int passed = run_command(argv, &result) == 0 &&
                     !result.timed_out &&
                     result.exit_code >= 0 &&
                     result.exit_code < 128 &&
                     result.output_len > 0;
        report_result("Parallel mode exits cleanly", passed, &tests_run, &tests_passed);
    }

    printf("Tests: %d/%d passed (%s)\n",
           tests_passed,
           tests_run,
           tests_passed == tests_run ? "ALL PASSED" : "SOME FAILED");

    return tests_passed == tests_run ? 0 : 1;
}
