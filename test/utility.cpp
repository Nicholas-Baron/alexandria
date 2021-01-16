#include "utility.h"

#include <boost_ut/ut.hpp>

int main() {
    using namespace boost::ut;

    "exchange moves a value while replacing it"_test = [] {
        struct test_t final {
            int x;

            test_t(int val)
                : x{val} {}

            test_t(const test_t &) = delete;
            test_t(test_t &&) noexcept = default;

            test_t & operator=(const test_t &) = delete;
            test_t & operator=(test_t &&) noexcept = default;

            ~test_t() noexcept = default;
        };

        test_t src{1};
        test_t dest = alx::exchange(src, 2);
        expect(eq(src.x, 2));
        expect(eq(dest.x, 1));
    };

    "swap switches which values are in two variables"_test = [] {
        int x = 5;
        int y = 10;

        alx::swap(x, y);

        expect(eq(x, 10));
        expect(eq(y, 5));
    };
}
