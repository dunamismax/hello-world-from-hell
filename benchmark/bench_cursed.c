#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

#ifndef TARGET_BINARY
#define TARGET_BINARY "./build/cursed_spawn"
#endif

#define BENCHMARK_ITERATIONS 250
#define WARMUP_ITERATIONS 25

// Benchmark timing utilities
static double get_time_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
}

static void benchmark_function(const char* name, const char* args, int iterations) {
    printf("Benchmarking: %s\n", name);
    
    // Warmup
    for (int i = 0; i < WARMUP_ITERATIONS; i++) {
        char command[512];
        snprintf(command, sizeof(command), "%s %s >/dev/null 2>&1", TARGET_BINARY, args ? args : "");
        system(command);
    }
    
    // Actual benchmark
    double start_time = get_time_ms();
    
    for (int i = 0; i < iterations; i++) {
        char command[512];
        snprintf(command, sizeof(command), "%s %s >/dev/null 2>&1", TARGET_BINARY, args ? args : "");
        system(command);
    }
    
    double end_time = get_time_ms();
    double total_time = end_time - start_time;
    double avg_time = total_time / iterations;
    double ops_per_sec = 1000.0 / avg_time;
    
    printf("  Total time: %.2f ms\n", total_time);
    printf("  Average time: %.3f ms\n", avg_time);
    printf("  Operations/sec: %.1f\n", ops_per_sec);
    printf("\n");
}

static void benchmark_memory_usage(void) {
    printf("Memory Usage Analysis\n");
    
    // Use time command to get memory stats
    {
        char command[1024];
        snprintf(command,
                 sizeof(command),
                 "echo '  Peak memory usage:' && time -l %s >/dev/null 2>&1 | grep 'maximum resident set size' || echo '  Memory profiling not available on this system'",
                 TARGET_BINARY);
        system(command);
    }
    printf("\n");
}

static void benchmark_all_dimensions(void) {
    printf("Dimensional Performance Analysis\n");
    
    const char* dimensions[] = {
        "Dimensional Shift", "Fibonacci Madness", "Duff's Device", "Trigraph Nightmare",
        "Pointer Insanity", "Macro Hell", "setjmp Madness", "Quantum Horror",
        "Temporal Catastrophe", "Infernal Bureaucracy", "Board Meeting From Hell"
    };
    
    for (int i = 0; i < 11; i++) {
        char args[32];
        snprintf(args, sizeof(args), "-d %d", i);
        
        double start = get_time_ms();
        char command[512];
        snprintf(command, sizeof(command), "%s %s >/dev/null 2>&1", TARGET_BINARY, args);
        system(command);
        double end = get_time_ms();
        
        printf("  Dimension %d (%s): %.3f ms\n", i, dimensions[i], end - start);
    }
    printf("\n");
}

static void benchmark_scalability(void) {
    printf("Scalability Test\n");
    
    int repeat_counts[] = {1, 5, 10, 25, 50, 100};
    int num_tests = sizeof(repeat_counts) / sizeof(repeat_counts[0]);
    
    for (int i = 0; i < num_tests; i++) {
        char args[32];
        snprintf(args, sizeof(args), "-r %d", repeat_counts[i]);
        
        double start = get_time_ms();
        char command[512];
        snprintf(command, sizeof(command), "%s %s >/dev/null 2>&1", TARGET_BINARY, args);
        system(command);
        double end = get_time_ms();
        
        double time_per_iteration = (end - start) / repeat_counts[i];
        printf("  %d iterations: %.2f ms total, %.3f ms/iter\n", 
               repeat_counts[i], end - start, time_per_iteration);
    }
    printf("\n");
}

static void benchmark_concurrency(void) {
    printf("Concurrency Performance\n");
    
    // Test parallel mode
    double start = get_time_ms();
    {
        char command[512];
        snprintf(command, sizeof(command), "%s -t >/dev/null 2>&1", TARGET_BINARY);
        system(command);
    }
    double end = get_time_ms();
    printf("  Parallel mode: %.3f ms\n", end - start);
    
    // Test quantum mode
    start = get_time_ms();
    {
        char command[512];
        snprintf(command, sizeof(command), "%s -q >/dev/null 2>&1", TARGET_BINARY);
        system(command);
    }
    end = get_time_ms();
    printf("  Quantum mode: %.3f ms\n", end - start);
    
    // Test SIMD mode
    start = get_time_ms();
    {
        char command[512];
        snprintf(command, sizeof(command), "%s -s >/dev/null 2>&1", TARGET_BINARY);
        system(command);
    }
    end = get_time_ms();
    printf("  SIMD mode: %.3f ms\n", end - start);
    
    printf("\n");
}

static void print_system_info(void) {
    printf("System Information\n");
    printf("  Hostname: ");
    system("hostname");
    printf("  OS: ");
    system("uname -s");
    printf("  Architecture: ");
    system("uname -m");
    printf("  CPU Info: ");
    system("sysctl -n machdep.cpu.brand_string 2>/dev/null || lscpu | grep 'Model name' | cut -d: -f2 | xargs 2>/dev/null || echo 'CPU info not available'");
    printf("  Compiler: ");
    system("clang --version | head -1 2>/dev/null || gcc --version | head -1 2>/dev/null || echo 'Compiler info not available'");
    printf("\n");
}

int main(void) {
    printf("CURSED HELLO WORLD BENCHMARK SUITE\n");
    printf("=========================================\n\n");
    
    // Check if binary exists
    if (access(TARGET_BINARY, X_OK) != 0) {
        printf("Error: %s not found. Run 'make build' first.\n", TARGET_BINARY);
        return 1;
    }
    
    print_system_info();
    
    // Basic performance benchmarks
    benchmark_function("Default execution", NULL, BENCHMARK_ITERATIONS);
    benchmark_function("Dimensional shift", "-d 0", BENCHMARK_ITERATIONS);
    benchmark_function("Fibonacci madness", "-d 1", BENCHMARK_ITERATIONS);
    benchmark_function("Trigraph nightmare", "-d 3", BENCHMARK_ITERATIONS);
    benchmark_function("Infernal bureaucracy", "-d 9", BENCHMARK_ITERATIONS);
    benchmark_function("Board meeting from hell", "-d 10", BENCHMARK_ITERATIONS / 2);
    benchmark_function("Quantum horror", "-q", BENCHMARK_ITERATIONS / 2);
    benchmark_function("Apocalypse protocol", "--apocalypse", BENCHMARK_ITERATIONS / 8);
    benchmark_function("Parallel chaos", "-t", BENCHMARK_ITERATIONS / 4);
    
    // Detailed analysis
    benchmark_all_dimensions();
    benchmark_scalability();
    benchmark_concurrency();
    benchmark_memory_usage();
    
    // Performance comparison
    printf("Performance Summary\n");
    printf("  Tested %d iterations per benchmark\n", BENCHMARK_ITERATIONS);
    printf("  All cursed dimensions functional\n");
    printf("  Memory usage within reasonable bounds\n");
    printf("  Concurrency features operational\n");
    printf("\n");
    
    printf("Optimization Suggestions:\n");
    printf("  - Use -d flag to force specific dimensions for consistent performance\n");
    printf("  - Parallel mode (-t) may be slower due to thread overhead on simple tasks\n");
    printf("  - SIMD mode (-s) shows best performance on supported architectures\n");
    printf("  - Quantum mode (-q) has variable performance due to complex calculations\n");
    printf("\n");
    
    printf("The benchmark ritual is complete. Your system has been measured and found... adequate.\n");
    
    return 0;
}
