#include "counter.hpp"

counter::counter(size_t K, size_t seed) : A(K), random(seed) {
}

auto counter::get() -> uint {
    uint sum = 0;
    for (size_t i = 0; i < A.size(); ++i)
        sum += A[i];
    return sum;
}

void counter::inc() {
    auto i = random() % A.size();
    ++A[i];
}