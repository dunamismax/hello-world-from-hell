# BUILD

This document tracks the build and infrastructure evolution of this repository.
The project is intentionally over-engineered cursed C. It is a humor and education project.
The phases below reflect that honestly.

---

## Phase 1: The Cursed Core

- [x] Write `cursed.c` using trigraphs throughout
- [x] Implement multiple "dimensions" of cursed hello world output
- [x] Include macro abuse, setjmp/longjmp, threading, SIMD detours, and unnecessary math
- [x] Confirm the program compiles and produces recognizable hello world output

## Phase 2: Build Infrastructure

- [x] Write a Makefile with `build`, `run`, `clean`, and `help` targets
- [x] Use `clang` as the primary compiler with `-std=c17`
- [x] Add OS and architecture detection (`uname -s`, `uname -m`)
- [x] Add `-ftrigraphs` so the trigraph source actually compiles
- [x] Add a strict warning set: `-Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes`
- [x] Add a `debug` target that builds with `-fsanitize=address,undefined`
- [x] Emit binary size after compilation
- [x] Name the binary `cursed_spawn` for full thematic commitment

## Phase 3: Test and Benchmark Harnesses

- [x] Write `tests/test_cursed.c` as a plain C executable
- [x] Smoke-test help output, version output, repeat-count clamping, dimension wrapping
- [x] Include a non-hanging threaded mode test
- [x] Write `benchmark/bench_cursed.c` as a plain C executable
- [x] Add `make test` and `make bench` targets
- [x] Document that benchmarks are curiosity-grade, not rigorous

## Phase 4: Honest Build

- [x] Remove destructive `rm -rf` from `make clean`; scope it to `./build/`
- [x] Gate `make purge` behind `CONFIRM=YES`
- [x] Add `.DELETE_ON_ERROR` to the Makefile
- [x] Add a `profile` target using `time` and optional `valgrind`
- [x] Add a `hell` target that runs the full clean-build-test-demo cycle
- [x] Update README to reflect what the project actually is and is not

---

## Phase 5: Tech Stack Alignment

Even cursed C benefits from proper tooling. This phase closes gaps against the
C tech stack baseline without touching the intentionally cursed source code.

### Compiler and Warnings

- [ ] Add `-Wmissing-prototypes` to `UNHOLY_WARNINGS` and `UTILITY_WARNINGS`
- [ ] Add a `make gcc-check` target that builds with `CC=gcc` as a portability cross-check
- [ ] Verify the GCC build passes on both macOS (Homebrew GCC) and Linux

### Sanitizers

- [ ] Add a `make tsan` target that builds with `-fsanitize=thread` for the threaded dimension
- [ ] Confirm `make debug` (ASan + UBSan) and `make tsan` both pass cleanly
- [ ] Document in README that `make debug` and `make tsan` are the sanitizer entry points

### Static Analysis

- [ ] Add a `make scan` target that runs `scan-build make build`
- [ ] Add a `.clang-tidy` config that suppresses intentionally cursed patterns while still checking the test and benchmark sources
- [ ] Add a `make tidy` target that runs `clang-tidy` on `tests/test_cursed.c` and `benchmark/bench_cursed.c`

### Editor and LSP Support

- [ ] Add a `make compile-db` target (using `bear` or `compiledb`) that generates `compile_commands.json`
- [ ] Add `compile_commands.json` to `.gitignore`
- [ ] Add a `.clang-format` file so editors do not mangle the test and benchmark sources

### CI

- [ ] Add a GitHub Actions workflow that runs `make build`, `make test`, and `make debug` on both ubuntu-latest and macos-latest
- [ ] Add a GCC build step to the CI matrix
- [ ] Add a sanitizer step (`make debug`) to the CI matrix
- [ ] Keep CI intentionally minimal; do not add dependency managers or complex toolchains
