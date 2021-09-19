#include "counter.hpp"
#include <cassert>
#include <thread>

void test_basic() {
    counter cnt;
    assert(cnt.get() == 0);
    cnt.inc();
    assert(cnt.get() == 1);
}

void test_double_inc() {
    counter cnt;

    std::thread inc_1([&cnt] { cnt.inc(); });
    std::thread inc_2([&cnt] { cnt.inc(); });

    inc_1.join();
    inc_2.join();

    assert(cnt.get() == 2);
}

void test_two_threads() {
    counter cnt;

    std::thread t1([&cnt] {
        cnt.inc();
        assert(cnt.get() >= 1);
    });
    std::thread t2([&cnt] {
        cnt.inc();
        assert(cnt.get() >= 1);
    });

    t1.join();
    t2.join();
}

void test_single_counter() {
    counter cnt(1);

    std::thread inc_1([&cnt] { cnt.inc(); });
    std::thread inc_2([&cnt] { cnt.inc(); });
    std::thread get([&cnt] { assert(cnt.get() <= 2); });

    inc_1.join();
    inc_2.join();
    get.join();
}

int main() {
    test_basic();
    test_double_inc();
    test_two_threads();
    test_single_counter();

    return 0;
}