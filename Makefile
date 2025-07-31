CC = clang
CFLAGS = -O2 $(WARNINGS) -ftrigraphs
WARNINGS := -Wall -Wextra -Wpedantic
WARNINGS += -Wno-duplicate-decl-specifier -Wno-trigraphs

SRC = c.c

all:
	$(CC) $(CFLAGS) $(SRC)

clean:
	rm -f *.out

.PHONY: all clean