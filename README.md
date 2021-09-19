# Contention-aware counter

This is a C++ implementation of a counter that is split into multiple integer variables, the sum of which represents the counter value. On increment, the algorithm chooses a random integer variable and atomically increments it. To get the current counter value, the algorithm traverses over all the variables and sums them up.

## Files
- `counter.hpp`, `counter.cpp` — counter implementation
- `test.cpp` — concurrent tests
- `CMakeLists.txt` — specifies how to build and run the tests
- `Proof.md` — formal proof of counter linearizability

## GenMC (notes)
GenMC is said to support both C and C++, but unfortunately I haven't found and option to switch it to C++. It tries to compile my files as C code and fails with ` undeclared identifier` errors.