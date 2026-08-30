# Data Structures in C++

A collection of my implementations of different data structures and the algorithms
that use them. Implementations are added incrementally, based on my learning priorities.
Each implementation is to be added within its own CMake project.

## Goals

- Build a clear implementation of each structure.
- Understand the time and space trade-offs behind its operations.
- Practise testing, benchmarking, and documenting design decisions.
- Prefer handwritten code with the usage of AI for boilerplate and
  infrastructure.
- Experiment with paradigms such as Test Driven Development.

## Layout

```
data_structures/
cmake/                 # Shared CMake helpers
```

The `data_structures/` directory is the parent CMake project for individual
implementations.

## Prerequisites

- CMake 3.24 or newer
- A C++17-capable compiler (GCC, Clang, or MSVC)

## Build

Configure and build from the repository root:

```sh
cmake -S . -B build
cmake --build build
```

For a multi-config generator, select the build type while building:

```sh
cmake -S . -B build
cmake --build build --config Debug
```

Testing support is enabled by default. Once tests have been added, run them
with:

```sh
ctest --test-dir build --output-on-failure
```

## Adding a structure

1. Create a directory under `data_structures/` for the implementation.
2. Add its `CMakeLists.txt` with a library or executable target, then register
   it from `data_structures/CMakeLists.txt`.
3. Add focused tests under `tests/` and document operation complexity beside
   the implementation.
