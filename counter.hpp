#pragma once
#include <atomic>
#include <cstddef>
#include <random>
#include <vector>

class counter {
    using uint = unsigned int;
    std::vector<std::atomic<uint>> A;
    std::mt19937 random;

public:
    counter(size_t K = 3, size_t seed = 0);
    uint get();
    void inc();
};