# =============================================================================
# CURSED MAKEFILE FROM THE DEPTHS OF PROGRAMMING HELL
# Honest enough to be safe, cursed enough to stay funny
# =============================================================================

CC ?= clang
DEBUG ?= 0
TSAN ?= 0
GCC ?= gcc
BUILD_DIR ?= build

CURSED_SOURCE := cursed.c
TEST_SOURCE := tests/test_cursed.c
BENCH_SOURCE := benchmark/bench_cursed.c

INFERNAL_BINARY := $(BUILD_DIR)/cursed_spawn
TEST_BINARY := $(BUILD_DIR)/test_runner
BENCH_BINARY := $(BUILD_DIR)/bench_runner
TARGET_BINARY_PATH := $(abspath $(INFERNAL_BINARY))

UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)
CC_VERSION_LINE := $(shell $(CC) --version 2>/dev/null | head -n 1)

ifneq ($(findstring gcc,$(CC_VERSION_LINE))$(findstring GCC,$(CC_VERSION_LINE)),)
TRIGRAPH_FLAG := -trigraphs
else
TRIGRAPH_FLAG := -ftrigraphs
endif

OPTIMS := -O3 -march=native -flto -funroll-loops
DEBUG_FLAGS := -O0 -g3 -fsanitize=address,undefined -fno-omit-frame-pointer
SANITIZER_FLAGS := -fsanitize=address,undefined
TSAN_FLAGS := -O1 -g -fsanitize=thread -fno-omit-frame-pointer
TSAN_LDFLAGS := -fsanitize=thread
UNHOLY_WARNINGS := -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes -Wmissing-prototypes
UNHOLY_WARNINGS += -Wno-duplicate-decl-specifier -Wno-trigraphs -Wvla -Wformat=2
UTILITY_WARNINGS := -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes -Wmissing-prototypes

ifeq ($(UNAME_S),Darwin)
	OS_FLAGS := -DMACOS
	THREAD_FLAGS :=
else ifeq ($(UNAME_S),Linux)
	OS_FLAGS := -DLINUX
	THREAD_FLAGS := -pthread
else
	OS_FLAGS := -DUNKNOWN_OS
	THREAD_FLAGS :=
endif

ifeq ($(UNAME_M),x86_64)
	ARCH_FLAGS := -DX86_64
else ifeq ($(UNAME_M),arm64)
	ARCH_FLAGS := -DARM64
else
	ARCH_FLAGS := -DUNKNOWN_ARCH
endif

ifeq ($(DEBUG),1)
	MODE_CFLAGS := $(DEBUG_FLAGS)
	MODE_LDFLAGS := $(SANITIZER_FLAGS)
else ifeq ($(TSAN),1)
	MODE_CFLAGS := $(TSAN_FLAGS)
	MODE_LDFLAGS := $(TSAN_LDFLAGS)
else
	MODE_CFLAGS := $(OPTIMS)
	MODE_LDFLAGS := $(OPTIMS)
endif

CURSED_CFLAGS := $(MODE_CFLAGS) $(UNHOLY_WARNINGS) $(TRIGRAPH_FLAG) -std=c17 $(OS_FLAGS) $(ARCH_FLAGS) $(THREAD_FLAGS)
CURSED_LDFLAGS := $(MODE_LDFLAGS)
CURSED_LDLIBS := -lm $(THREAD_FLAGS)
UTILITY_CFLAGS := $(if $(filter 1,$(DEBUG)),-O0 -g3,-O2) $(UTILITY_WARNINGS) -std=c17 -D_POSIX_C_SOURCE=200809L

.DELETE_ON_ERROR:

# =============================================================================
# RITUALS OF COMPILATION
# =============================================================================

all: build

build: $(INFERNAL_BINARY)

$(INFERNAL_BINARY): $(CURSED_SOURCE)
	@mkdir -p $(BUILD_DIR)
	@echo "Invoking the compiler daemon..."
	@echo "Feeding trigraphs to the machine spirits..."
	@echo "Compiling with $(CC) for $(UNAME_S)/$(UNAME_M)"
	$(CC) $(CURSED_CFLAGS) $(CURSED_SOURCE) -o $(INFERNAL_BINARY) $(CURSED_LDFLAGS) $(CURSED_LDLIBS)
	@echo "The cursed binary has been forged in $(INFERNAL_BINARY)."
	@echo "Binary size: $$(du -h $(INFERNAL_BINARY) | cut -f1)"

$(TEST_BINARY): $(TEST_SOURCE) $(INFERNAL_BINARY)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(UTILITY_CFLAGS) -DTARGET_BINARY=\"$(TARGET_BINARY_PATH)\" $(TEST_SOURCE) -o $(TEST_BINARY)

$(BENCH_BINARY): $(BENCH_SOURCE) $(INFERNAL_BINARY)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(UTILITY_CFLAGS) -DTARGET_BINARY=\"$(TARGET_BINARY_PATH)\" $(BENCH_SOURCE) -o $(BENCH_BINARY)

run: $(INFERNAL_BINARY)
	@echo "Executing the digital incantation..."
	./$(INFERNAL_BINARY) || echo "The demon has returned to the abyss with exit code $$?"

summon: run

test: $(INFERNAL_BINARY) $(TEST_BINARY)
	@echo "Running cursed test suite..."
	./$(TEST_BINARY)

bench: $(INFERNAL_BINARY) $(BENCH_BINARY)
	@echo "Running performance benchmarks from hell..."
	./$(BENCH_BINARY)

hell: clean build test
	@echo "================================================================="
	@echo "           CURSED HELLO WORLD - COMPLETE RITUAL"
	@echo "================================================================="
	@echo ""
	@echo "Binary forged successfully. Size: $$(du -h $(INFERNAL_BINARY) | cut -f1)"
	@echo ""
	@echo "Testing help system..."
	@./$(INFERNAL_BINARY) --help | head -5
	@echo ""
	@echo "Demonstrating cursed dimensions..."
	@echo "  Dimension 0 (Dimensional shift): $$(./$(INFERNAL_BINARY) -d 0 2>&1 | head -1 | cut -c1-30)..."
	@echo "  Dimension 1 (Fibonacci madness): $$(./$(INFERNAL_BINARY) -d 1 2>&1 | head -1 | cut -c1-30)..."
	@echo "  Dimension 3 (Trigraph nightmare): $$(./$(INFERNAL_BINARY) -d 3 2>&1 | head -1 | cut -c1-30)..."
	@echo "  Dimension 9 (Infernal bureaucracy): $$(./$(INFERNAL_BINARY) -d 9 2>&1 | head -1 | cut -c1-30)..."
	@echo "  Apocalypse protocol: $$(./$(INFERNAL_BINARY) --apocalypse 2>&1 | head -1 | cut -c1-30)..."
	@echo ""
	@echo "Quick performance test (10 iterations)..."
	@time -p sh -c 'for i in $$(seq 1 10); do ./$(INFERNAL_BINARY) -d 0 >/dev/null 2>&1; done' 2>&1 | grep real
	@echo ""
	@echo "================================================================="
	@echo "The complete ritual is finished. Hell has been unleashed."
	@echo "Your terminal has survived... barely."
	@echo "================================================================="

banish:
	@echo "Banishing generated artifacts under $(BUILD_DIR)..."
	rm -rf $(BUILD_DIR)
	@echo "The digital realm has been cleansed."

clean: banish

debug:
	@echo "Building and testing with ASan + UBSan..."
	$(MAKE) DEBUG=1 clean test

tsan:
	@echo "Building and testing with ThreadSanitizer..."
	$(MAKE) TSAN=1 clean test

gcc-check:
	@echo "Cross-checking the cursed build with $(GCC)..."
	$(MAKE) CC="$(GCC)" clean build test

profile: $(INFERNAL_BINARY)
	@echo "Profiling the cursed execution..."
	time -p ./$(INFERNAL_BINARY)
	valgrind --tool=callgrind --collect-jumps=yes ./$(INFERNAL_BINARY) 2>/dev/null || echo "Valgrind not available"

purge:
	@if [ "$(CONFIRM)" != "YES" ]; then \
		echo "Refusing to purge without CONFIRM=YES."; \
		echo "This target only removes generated files and common local junk."; \
		exit 2; \
	fi
	@echo "Performing the confirmed exorcism..."
	rm -rf $(BUILD_DIR) *.dSYM
	rm -f core core.* *.tmp *.temp .DS_Store *~ callgrind.out.*
	@echo "Generated traces have been erased."

help:
	@echo "==================================================================="
	@echo "           CURSED MAKEFILE - COMMANDS FROM THE ABYSS"
	@echo "==================================================================="
	@echo ""
	@echo "Primary Incantations:"
	@echo "  make build     - Forge the cursed binary at $(INFERNAL_BINARY)"
	@echo "  make run       - Execute the digital incantation"
	@echo "  make test      - Build the binary and run deterministic smoke tests"
	@echo "  make bench     - Build the binary and run curiosity-grade benchmarks"
	@echo ""
	@echo "Cleanup Rituals:"
	@echo "  make clean     - Remove generated files under $(BUILD_DIR)"
	@echo "  make purge     - Remove generated files plus local junk (requires CONFIRM=YES)"
	@echo ""
	@echo "Advanced Dark Arts:"
	@echo "  make hell      - Clean, build, test, and demo a few cursed modes"
	@echo "  make debug     - Build and test with ASan + UBSan"
	@echo "  make tsan      - Build and test with ThreadSanitizer"
	@echo "  make gcc-check - Cross-check build and tests with GCC (override GCC=... if needed)"
	@echo "  make profile   - Time the cursed binary and try valgrind if present"
	@echo "  make help      - Display this forbidden knowledge"
	@echo ""
	@echo "WARNING: This code contains:"
	@echo "  - Trigraph sorcery that would make demons weep"
	@echo "  - Macro expansion from the ninth circle of hell"
	@echo "  - Output that is intentionally weird, not reliable"
	@echo ""
	@echo "Expected output: Hello World! (or a cursed mutation thereof)"
	@echo "==================================================================="

.PHONY: all build run summon test bench hell banish clean debug tsan gcc-check profile purge help
