#include "unique_ptr.h"

#include <boost_ut/ut.hpp>

int main() {
    using namespace boost::ut;
    using alx::unique_ptr;

    "a default unique_ptr is null"_test = [] {
        unique_ptr<int> ptr;
        expect(ptr == nullptr);
    };

    "a unique_ptr can take ownership of a pointer"_test = [] {
        unique_ptr<int> ptr{new int{10}};
        expect(ptr != nullptr);
        expect(*ptr == 10_i);
    };

    "a unique_ptr can be passed thru using ->"_test = [] {
        struct target final {
            int value;
            constexpr target(int val) noexcept
                : value{val} {}
        };
        unique_ptr<target> ptr{new target{10}};
        expect(ptr->value == 10_i);
    };

    "a unique_ptr can be created with make_unique"_test = [] {
        auto ptr = alx::make_unique<int>(10);
        expect(ptr != nullptr);
        expect(*ptr == 10_i);
    };

    "a moved-from unique_ptr is null"_test = [] {
        auto src = alx::make_unique<int>(5);
        auto dest = move(src);

        expect(src == nullptr);
        expect(dest != nullptr);
        expect(*dest == 5_i);
    };
}
