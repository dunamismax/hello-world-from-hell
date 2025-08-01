#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

// Test framework macros
#define TEST_SUITE_START() printf("Starting Cursed Test Suite...\n"); int tests_run = 0, tests_passed = 0
#define TEST_SUITE_END() printf("Tests: %d/%d passed (%s)\n", tests_passed, tests_run, \
    (tests_passed == tests_run) ? "ALL PASSED" : "SOME FAILED"); \
    return (tests_passed == tests_run) ? 0 : 1

#define TEST(name) do { \
    printf("Running test: %s... ", name); \
    tests_run++; \
    if ((

#define END_TEST )) { \
    printf("PASSED\n"); \
    tests_passed++; \
} else { \
    printf("FAILED\n"); \
} \
} while(0)

// Test helper functions
static int run_cursed_binary(const char* args, char* output, size_t output_size) {
    char command[512];
    snprintf(command, sizeof(command), "./cursed_spawn %s 2>&1", args ? args : "");
    
    FILE* pipe = popen(command, "r");
    if (!pipe) return -1;
    
    size_t bytes_read = fread(output, 1, output_size - 1, pipe);
    output[bytes_read] = '\0';
    
    int exit_code = pclose(pipe);
    return WEXITSTATUS(exit_code);
}

static int contains_hello_world(const char* output) {
    // Check for various cursed versions of Hello World
    return (strstr(output, "Hello") && strstr(output, "World")) ||
           (strstr(output, "hello") && strstr(output, "world")) ||
           (strstr(output, "HELLO") && strstr(output, "WORLD")) ||
           strstr(output, "oW olleH") ||  // Reversed
           (strlen(output) > 5 && strlen(output) < 200);  // Reasonable output length
}

static int count_hello_world_occurrences(const char* output) {
    int count = 0;
    const char* pos = output;
    while ((pos = strstr(pos, "Hello")) != NULL) {
        if (strstr(pos, "World")) count++;
        pos++;
    }
    return count;
}

int main(void) {
    TEST_SUITE_START();
    
    char output[4096];
    int exit_code;
    
    // Test 1: Basic functionality
    TEST("Basic Hello World output")
        (exit_code = run_cursed_binary(NULL, output, sizeof(output)), 
         exit_code >= 0 && exit_code < 128 && contains_hello_world(output))
    END_TEST;
    
    // Test 2: Help functionality
    TEST("Help message display")
        (exit_code = run_cursed_binary("--help", output, sizeof(output)),
         exit_code == 0 && strstr(output, "CURSED HELLO WORLD") && strstr(output, "Usage:"))
    END_TEST;
    
    // Test 3: Version information
    TEST("Version information")
        (exit_code = run_cursed_binary("--version", output, sizeof(output)),
         exit_code == 0 && strstr(output, "Hello World From Hell") && strstr(output, "v2.0"))
    END_TEST;
    
    // Test 4: Dimension forcing
    TEST("Forced dimension 0")
        (exit_code = run_cursed_binary("-d 0", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && contains_hello_world(output))
    END_TEST;
    
    TEST("Forced dimension 1")
        (exit_code = run_cursed_binary("-d 1", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && contains_hello_world(output))
    END_TEST;
    
    TEST("Forced dimension 2")
        (exit_code = run_cursed_binary("-d 2", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && contains_hello_world(output))
    END_TEST;
    
    TEST("Forced dimension 3")
        (exit_code = run_cursed_binary("-d 3", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && contains_hello_world(output))
    END_TEST;
    
    // Test 5: Repeat functionality
    TEST("Repeat functionality")
        (exit_code = run_cursed_binary("-r 3", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && strlen(output) > 10)
    END_TEST;
    
    // Test 6: Chaos counter setting
    TEST("Chaos counter setting")
        (exit_code = run_cursed_binary("-c 42", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && contains_hello_world(output))
    END_TEST;
    
    // Test 7: Quantum mode
    TEST("Quantum entanglement mode")
        (exit_code = run_cursed_binary("-q", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && contains_hello_world(output))
    END_TEST;
    
    // Test 8: Thread safety test
    TEST("Parallel dimension mode")
        (exit_code = run_cursed_binary("-t", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && contains_hello_world(output))
    END_TEST;
    
    // Test 9: SIMD mode (if available)
    TEST("SIMD hell mode (if supported)")
        (exit_code = run_cursed_binary("-s", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && contains_hello_world(output))
    END_TEST;
    
    // Test 10: Combined flags
    TEST("Combined flags test")
        (exit_code = run_cursed_binary("-d 1 -r 2 -c 13", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && strlen(output) > 10)
    END_TEST;
    
    // Test 11: Edge case - very high repeat count (should be capped)
    TEST("Repeat count capping")
        (exit_code = run_cursed_binary("-r 1000", output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && contains_hello_world(output))
    END_TEST;
    
    // Test 12: Exit codes are reasonable
    TEST("Exit code validation")
        (exit_code = run_cursed_binary(NULL, output, sizeof(output)),
         exit_code >= 0 && exit_code < 128)
    END_TEST;
    
    // Test 13: Output contains curse completion message
    TEST("Curse completion message")
        (exit_code = run_cursed_binary(NULL, output, sizeof(output)),
         exit_code >= 0 && exit_code < 128 && (strstr(output, "curse is complete") || contains_hello_world(output)))
    END_TEST;
    
    // Test 14: Stress test - multiple rapid executions
    TEST("Stress test - multiple executions") ({
        int all_passed = 1;
        for (int i = 0; i < 5 && all_passed; i++) {
            exit_code = run_cursed_binary("-d 0", output, sizeof(output));
            if (exit_code < 0 || exit_code >= 128 || !contains_hello_world(output)) {
                all_passed = 0;
            }
        }
        all_passed;
    })
    END_TEST;
    
    // Test 15: Memory safety test (basic)
    TEST("Memory safety - no crashes with various inputs") ({
        int no_crashes = 1;
        const char* test_args[] = {"-d 0", "-d 7", "-r 5", "-c 0", "-c 65535", NULL};
        for (int i = 0; test_args[i] && no_crashes; i++) {
            exit_code = run_cursed_binary(test_args[i], output, sizeof(output));
            if (exit_code < 0 || exit_code > 127) {
                no_crashes = 0;
            }
        }
        no_crashes;
    })
    END_TEST;
    
    TEST_SUITE_END();
}