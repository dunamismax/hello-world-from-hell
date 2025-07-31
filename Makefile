# =============================================================================
# CURSED MAKEFILE FROM THE DEPTHS OF PROGRAMMING HELL
# Abandon all hope, ye who compile here
# =============================================================================

# The dark compiler of choice
CC = clang
CFLAGS = -O2 $(UNHOLY_WARNINGS) -ftrigraphs
UNHOLY_WARNINGS := -Wall -Wextra -Wpedantic
UNHOLY_WARNINGS += -Wno-duplicate-decl-specifier -Wno-trigraphs

# Source of all evil
CURSED_SOURCE = cursed.c
INFERNAL_BINARY = cursed_spawn

# =============================================================================
# RITUALS OF COMPILATION
# =============================================================================

# Default target - summon the darkness
all: $(INFERNAL_BINARY)

# Primary incantation - cleanse, build, and unleash hell
hell: banish $(INFERNAL_BINARY) summon
	@echo "The ritual is complete. Hell has been unleashed upon this terminal."

# Build the abomination
build: $(INFERNAL_BINARY)

$(INFERNAL_BINARY): $(CURSED_SOURCE)
	@echo "Invoking the compiler daemon..."
	@echo "Feeding trigraphs to the machine spirits..."
	$(CC) $(CFLAGS) $(CURSED_SOURCE) -o $(INFERNAL_BINARY)
	@echo "The cursed binary has been forged in the fires of compilation."

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

# Purge everything with extreme prejudice
purge: banish
	@echo "Performing complete exorcism of build artifacts..."
	rm -f core core.* *.tmp *.temp .DS_Store *~
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

.PHONY: all hell build run summon banish clean purge help