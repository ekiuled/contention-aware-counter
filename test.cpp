#include "counter.hpp"
#include <cassert>

void test_basic() {
    counter cnt;
    assert(cnt.get() == 0);
    cnt.inc();
    assert(cnt.get() == 1);
}

void test_concurrent() {
    
}

int main() {
    test_basic();
    test_concurrent();

    return 0;
}