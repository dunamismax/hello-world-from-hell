<p align="center">
  <img src="assets/images/hello-world-from-hell.png" alt="Hello World From Hell PNG" width="400" />
</p>

_A novelty C repo whose entire purpose is to do "Hello World" in the most overcommitted, theatrical, audit-resistant way possible._

This repository is a joke, a code-reading dare, a trigraph crime scene, and now a small bureaucracy simulator for demons.

It is not a serious systems project. It is a deliberately polished piece of cursed nonsense.

## What It Actually Is

`cursed.c` is an intentionally unhinged C program that produces Hello-World-ish output through combinations of:

- trigraphs
- macro abuse
- setjmp/longjmp detours
- atomics and threads
- SIMD side quests
- pointer rituals
- recursive nonsense
- board-approved apocalypse
- a qsort-backed infernal paperwork system

The repo is supposed to make you laugh, squint, and ask "why does this compile at all?" It is meant to be funny, intentional, and barely respectable enough to build cleanly on purpose.

## New Escalations In This Version

The repo now pushes harder into "absolutely unhinged C program" territory while keeping the bit coherent.

Highlights:

- **Temporal loop catastrophe** is now an exposed dimension instead of hidden ambient damage.
- **Infernal bureaucracy** prints `Hello World!` by sorting cursed permit records and dispatching macro-generated emitters.
- **Board meeting from hell** prints the greeting as if it had to survive a demonic committee vote.
- **Apocalypse protocol** chains multiple dimensions together behind `-a` / `--apocalypse` and turns the repo into a full ritual instead of a single bad decision.
- Benchmarks were trimmed to curiosity-grade scale so they still feel stupid without taking forever.
- Tests were expanded to pin the new deterministic horrors down where that still makes sense.

## What It Is Not

- Not a production artifact
- Not a portability guarantee
- Not a trustworthy benchmark suite
- Not an example of sane C architecture
- Not guaranteed to print one clean `Hello World!` on every path
- Not interested in your code review unless your code review is also cursed

## Build And Run

```bash
make build
./build/cursed_spawn
./build/cursed_spawn --help
./build/cursed_spawn --apocalypse
```

Useful targets:

```bash
make build                     # Build the main binary into ./build/
make run                       # Run the default cursed mode
make test                      # Build the binary and run deterministic smoke tests
make bench                     # Run curiosity-grade benchmarks
make debug                     # Build and test with ASan + UBSan
make tsan                      # Build and test with ThreadSanitizer
make gcc-check                 # Cross-check build + tests with GCC
make gcc-check GCC=gcc-15      # macOS/Homebrew GCC example
make clean                     # Remove generated files under ./build/
make purge CONFIRM=YES         # Stronger cleanup, only with confirmation
make hell                      # Clean, build, test, and demo several cursed modes
```

`make debug` and `make tsan` are the sanitizer entry points for the repo.

`make gcc-check` is the boring portability spot-check. On Linux, the default `GCC=gcc` should be fine. On macOS, `/usr/bin/gcc` is usually Apple Clang wearing a fake mustache, so pass your Homebrew binary explicitly, such as `GCC=gcc-15`.

## Interesting CLI Modes

```bash
./build/cursed_spawn -d 9          # Infernal bureaucracy
./build/cursed_spawn -d 10         # Board meeting from hell
./build/cursed_spawn -d 8          # Temporal loop catastrophe
./build/cursed_spawn -q            # Quantum entanglement horror
./build/cursed_spawn -t            # Parallel nightmare mode
./build/cursed_spawn --apocalypse  # Compliance collapse ceremony
```

`--help` documents the numbered dimensions that are stable enough to force directly.

## Tests

`make test` builds the real binary first, then runs a small deterministic harness against explicit modes and CLI behavior.

It checks things like:

- help and version output
- exact byte sequences for selected dimensions
- dimension wrapping
- repeat-count clamping
- the new infernal bureaucracy and board-meeting outputs
- apocalypse protocol containment
- a non-hanging threaded mode

The tests do **not** pretend the repo is universally deterministic. They only pin down the paths that are supposed to stay pinned down.

## Benchmarks

`make bench` exists because a repo this ridiculous deserves fake gravitas.

The benchmark harness is intentionally lightweight, still process-launch-heavy, and still not rigorous. It now includes the newer derangements such as infernal bureaucracy, board meeting from hell, and apocalypse protocol.

Use the numbers for amusement, not engineering decisions.

## CI And Tooling Stance

GitHub Actions runs the boring checks that actually matter here:

- build + test on Ubuntu and macOS
- a Linux GCC cross-check
- sanitizer passes through `make debug` and `make tsan`

That is enough discipline for a joke repo with real C footguns.

The repo intentionally does **not** grow a large tooling bureaucracy around the joke. For now there is no `clang-tidy`, `scan-build`, or compile-database pipeline checked in. If the repo somehow becomes maintenance-heavy later, that can change then instead of pretending now.

## Cleanup Safety

`make clean` only removes generated files in `./build/`.

`make purge` is gated:

```bash
make purge CONFIRM=YES
```

That target is still limited to generated files and common local junk. It does not wipe source directories.

## Intentionally Retained Absurdity

The repo still keeps the parts that make the joke work:

- trigraph-heavy source
- melodramatic make output
- cursed mode names
- bizarre output mutations
- benchmark theater
- documentation that tells the truth about the crime

If you want a normal Hello World, this repository remains aggressively incorrect for that purpose.
