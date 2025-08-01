# =============================================================================
# CURSED MAKEFILE FROM THE DEPTHS OF PROGRAMMING HELL
# Abandon all hope, ye who compile here
# =============================================================================

# The dark compiler of choice - now with infernal intelligence
CC ?= clang
DEBUG ?= 0
OPTIMS = -O3 -march=native -flto -funroll-loops
DEBUG_FLAGS = -O0 -g3 -fsanitize=address,undefined -fno-omit-frame-pointer
CFLAGS = $(if $(filter 1,$(DEBUG)),$(DEBUG_FLAGS),$(OPTIMS)) $(UNHOLY_WARNINGS) -ftrigraphs -std=c17
UNHOLY_WARNINGS := -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes
UNHOLY_WARNINGS += -Wno-duplicate-decl-specifier -Wno-trigraphs -Wvla -Wformat=2
LDFLAGS = $(if $(filter 1,$(DEBUG)),-fsanitize=address,$(OPTIMS))

# Source of all evil
CURSED_SOURCE = cursed.c
INFERNAL_BINARY = cursed_spawn
TEST_SOURCE = tests/test_cursed.c
TEST_BINARY = tests/test_runner
BENCH_SOURCE = benchmark/bench_cursed.c
BENCH_BINARY = benchmark/bench_runner

# Architecture detection for maximum portability
UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)
ifeq ($(UNAME_S),Darwin)
	OS_FLAGS = -DMACOS
else ifeq ($(UNAME_S),Linux)
	OS_FLAGS = -DLINUX
else
	OS_FLAGS = -DUNKNOWN_OS
endif

ifeq ($(UNAME_M),x86_64)
	ARCH_FLAGS = -DX86_64
else ifeq ($(UNAME_M),arm64)
	ARCH_FLAGS = -DARM64
else
	ARCH_FLAGS = -DUNKNOWN_ARCH
endif

CFLAGS += $(OS_FLAGS) $(ARCH_FLAGS)

# =============================================================================
# RITUALS OF COMPILATION
# =============================================================================

# Default target - summon the darkness
all: $(INFERNAL_BINARY)

# Primary incantation - cleanse, build, demonstrate, test, and unleash hell
hell: banish $(INFERNAL_BINARY) 
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
	@echo ""
	@echo "Testing advanced features..."
	@echo "  SIMD hell: $$(./$(INFERNAL_BINARY) -s 2>&1 | head -1 | cut -c1-30)..."
	@echo "  Quantum horror: $$(./$(INFERNAL_BINARY) -q 2>&1 | head -1 | cut -c1-30)..."
	@echo "  Parallel chaos: $$(./$(INFERNAL_BINARY) -t 2>&1 | head -1 | cut -c1-30)..."
	@echo ""
	@echo "Running test suite..."
	@$(MAKE) test 2>&1 | grep "Tests:"
	@echo ""
	@echo "Quick performance test (10 iterations)..."
	@time -p (for i in $$(seq 1 10); do ./$(INFERNAL_BINARY) -d 0 >/dev/null 2>&1; done) 2>&1 | grep real
	@echo ""
	@echo "================================================================="
	@echo "The complete ritual is finished. Hell has been unleashed."
	@echo "Your terminal has survived... barely."
	@echo "================================================================="

# Build the abomination
build: $(INFERNAL_BINARY)

$(INFERNAL_BINARY): $(CURSED_SOURCE)
	@echo "Invoking the compiler daemon..."
	@echo "Feeding trigraphs to the machine spirits..."
	@echo "Compiling with $(CC) for $(UNAME_S)/$(UNAME_M)"
	$(CC) $(CFLAGS) $(LDFLAGS) $(CURSED_SOURCE) -o $(INFERNAL_BINARY)
	@echo "The cursed binary has been forged in the fires of compilation."
	@echo "Binary size: $$(du -h $(INFERNAL_BINARY) | cut -f1)"

# Execute the hellish creation
run: $(INFERNAL_BINARY)
	@echo "Executing the digital incantation..."
	./$(INFERNAL_BINARY) || echo "The demon has returned to the abyss with exit code $$?"

# Summon hell (clean, build, run)
summon: $(INFERNAL_BINARY)
	@echo "Summoning the cursed output..."
	./$(INFERNAL_BINARY) || echo "The demon has returned to the abyss with exit code $$?"

# Banish all compiled demons
banish:
	@echo "Banishing compiled demons back to the void..."
	rm -f $(INFERNAL_BINARY) *.out *.o
	@echo "The digital realm has been cleansed."

# Standard clean target for the uninitiated
clean: banish

# Test the cursed creation
test: $(TEST_BINARY)
	@echo "Running cursed test suite..."
	./$(TEST_BINARY)

$(TEST_BINARY): $(TEST_SOURCE) $(CURSED_SOURCE)
	@mkdir -p tests
	$(CC) $(CFLAGS) -DTEST_MODE $(TEST_SOURCE) -o $(TEST_BINARY)

# Benchmark the infernal performance
bench: $(BENCH_BINARY)
	@echo "Running performance benchmarks from hell..."
	./$(BENCH_BINARY)

$(BENCH_BINARY): $(BENCH_SOURCE) $(CURSED_SOURCE)
	@mkdir -p benchmark
	$(CC) $(CFLAGS) -DBENCH_MODE $(BENCH_SOURCE) -o $(BENCH_BINARY)

# Debug build with all the hellish safety checks
debug:
	@echo "Building debug version with address sanitizer..."
	$(MAKE) DEBUG=1 $(INFERNAL_BINARY)

# Profile the cursed code
profile: $(INFERNAL_BINARY)
	@echo "Profiling the cursed execution..."
	time -p ./$(INFERNAL_BINARY)
	valgrind --tool=callgrind --collect-jumps=yes ./$(INFERNAL_BINARY) 2>/dev/null || echo "Valgrind not available"

# Purge everything with extreme prejudice
purge: banish
	@echo "Performing complete exorcism of build artifacts..."
	rm -f core core.* *.tmp *.temp .DS_Store *~
	rm -rf tests/ benchmark/ *.dSYM/ callgrind.out.*
	@echo "All traces of our dark work have been erased."

# Show the forbidden knowledge
help:
	@echo "==================================================================="
	@echo "           CURSED MAKEFILE - COMMANDS FROM THE ABYSS"
	@echo "==================================================================="
	@echo ""
	@echo "Primary Incantations:"
	@echo "  make hell      - The main ritual: banish, build, then summon"
	@echo "  make summon    - Execute the cursed binary"
	@echo "  make banish    - Destroy all compiled demons"
	@echo ""
	@echo "Standard Rituals:"
	@echo "  make           - Default: compile the abomination"
	@echo "  make build     - Forge the cursed binary"
	@echo "  make run       - Execute the digital incantation"
	@echo "  make clean     - Cleanse build artifacts"
	@echo ""
	@echo "Advanced Dark Arts:"
	@echo "  make purge     - Complete exorcism of all artifacts"
	@echo "  make help      - Display this forbidden knowledge"
	@echo ""
	@echo "WARNING: This code contains:"
	@echo "  - Trigraph sorcery that would make demons weep"
	@echo "  - Macro expansion from the ninth circle of hell"
	@echo "  - Seven different methods of cursed output"
	@echo "  - Enough obfuscation to traumatize compilers"
	@echo ""
	@echo "Expected output: Hello World! (or variations thereof)"
	@echo "Side effects: Existential dread, loss of faith in humanity"
	@echo "==================================================================="

.PHONY: all hell build run summon banish clean purge help test bench debug profile