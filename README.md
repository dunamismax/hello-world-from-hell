<p align="center">
  <img src="assets/images/hello-world-from-hell.png" alt="Hello World From Hell PNG" width="400" />
</p>

_A novelty C repo whose entire purpose is to do "Hello World" the wrong way on purpose._

This repository is a joke, a code-reading dare, and a mildly irresponsible trigraph exhibit. It is not a serious systems project, not a trustworthy benchmark suite, and not a model of robust C design.

## What It Actually Is

`cursed.c` is an intentionally overcooked program that produces Hello-World-ish output through:

- trigraphs
- macro abuse
- awkward control flow
- threading
- SIMD detours
- unnecessary math

The result is supposed to be entertainingly bad, not precise, portable in every environment, or operationally meaningful.

## What It Is Not

- Not a production artifact
- Not a reliable portability test
- Not a serious performance benchmark
- Not an example of how to structure C code
- Not guaranteed to print the same clean `Hello World!` every time

## Build And Run

```bash
make build
./build/cursed_spawn
./build/cursed_spawn --help
```

Useful targets:

```bash
make build     # Build the main binary into ./build/
make run       # Run the default cursed mode
make test      # Build the binary and run deterministic smoke tests
make bench     # Run curiosity-grade benchmarks
make clean     # Remove generated files under ./build/
make purge     # Stronger cleanup, only with CONFIRM=YES
make hell      # Clean, build, test, and demo a few modes
```

## Tests

`make test` now builds the real binary first, then runs a small deterministic harness against explicit modes and CLI behavior. The tests intentionally avoid pretending this program is stable in every random or threaded path.

They verify things like:

- help and version output
- exact byte sequences for a few fixed dimensions
- repeat-count clamping
- dimension wrapping
- a non-hanging threaded mode

## Benchmarks

`make bench` exists because the repo would feel incomplete without fake gravitas, but the numbers are for amusement only. They are process-launch-heavy and not rigorous.

## Cleanup Safety

`make clean` only removes generated files in `./build/`.

`make purge` is gated:

```bash
make purge CONFIRM=YES
```

That target is still limited to generated files and common local junk. It no longer wipes source directories.

## Intentionally Retained Absurdity

The repo still keeps the parts that make the joke work:

- trigraph-heavy source
- melodramatic make output
- cursed mode names
- bizarre output mutations
- benchmark theater

If you want a normal Hello World, this is the wrong repository.
