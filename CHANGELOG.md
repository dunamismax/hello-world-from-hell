# Changelog

All notable changes to this cursed repository will be documented in this file.

## [3.0.1] - 2026-03-31

### Added
- `make tsan` as a ThreadSanitizer entry point for the threaded horrors.
- `make gcc-check` as the portability spot-check target, with explicit `GCC=...` override support.
- Minimal GitHub Actions CI for build, test, sanitizer, and Linux GCC coverage.

### Changed
- `make debug` now runs the deterministic test harness against the ASan + UBSan build instead of only producing a binary.
- README now carries the durable tooling guidance that used to sit in `BUILD.md`.
- Warning baselines now include `-Wmissing-prototypes` for both the cursed binary and the utility test/benchmark sources.
- Compiler flag selection now uses the right trigraph switch for Clang versus GCC during portability checks.

### Fixed
- `trigraph_nightmare()` now preserves its weird embedded NUL output without walking one byte past the static message buffer under ASan.

### Removed
- `BUILD.md`, because the repo is past the greenfield phase and the remaining stable guidance now lives in README plus CI.

## [3.0.0] - 2026-03-29

First official GitHub release.

### Added
- Apocalypse protocol CLI mode via `-a` / `--apocalypse`.
- Three new forced dimensions: temporal loop catastrophe, infernal bureaucracy, and board meeting from hell.
- Expanded deterministic coverage for the newer cursed dimensions.
- `BUILD.md` to track the repo's build and infrastructure phases.

### Changed
- Version output now uses semver `v3.0.0` for the official release.
- Benchmark coverage was retuned so the newer horrors still complete quickly enough to be amusing.
- README now reflects the current repo shape, localized image asset path, and honest build/cleanup behavior.

### Fixed
- Temporal catastrophe output walking so the repo stays cursed without drifting into accidental garbage reads.
- Build cleanup semantics so generated artifacts stay scoped to `./build/` and full purge remains confirmation-gated.
- `make debug` now rebuilds from a clean state so the advertised sanitizer build actually takes effect.
