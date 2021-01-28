#include "optional.h"

#include <boost_ut/ut.hpp>

struct destructor_check final {
    static inline unsigned destroyed_count{0};
    ~destructor_check() noexcept { destroyed_count++; }
};

int main() {
    using namespace boost::ut;
    using alx::optional;

    "an optional initially has no value"_test = [] {
        optional<int> opt;
        expect(not opt.has_value());
    };

    "an optional can take an inital value"_test = [] {
        optional<int> opt = 10;
        expect(opt.has_value());
        expect(opt.value() == 10_i);
    };

    "the arrow operator (->) can be used to call thru an optional"_test = [] {
        struct target final {
            int function() { return 5; }
        };

        optional opt = target{};

        expect(opt->function() == 5_i);
    };

    "an optional can have release its value"_test = [] {
        struct target final {
            target(int val)
                : value{val} {}
            target(const target &) = delete;
            target(target &&) = default;
            int value;
        };

        optional<target> opt{5};

        expect(opt.has_value());

        auto data = opt.release_value();

        expect(not opt.has_value());
        expect(data.value == 5_i);
    };

    "an optional can reset to the empty state"_test = [] {
        optional opt = destructor_check{};

        expect(opt.has_value());
        auto old_destroyed_count = destructor_check::destroyed_count;

        opt.reset();

        expect(not opt.has_value());
        expect(destructor_check::destroyed_count == 1 + old_destroyed_count);
    };
}
