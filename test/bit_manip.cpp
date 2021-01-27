#include "bit_manip.h"

#include <boost_ut/ut.hpp>

int main() {
    using namespace boost::ut;

    "popcount returns the number of 'on' bits in a number"_test = [] {
        using alx::popcount;
        expect(popcount(0) == 0_i);

        for (int i = 0; i < 4; i++) expect(eq(popcount(1 << i), 1));

        expect(eq(popcount(15), 4));
    };

    "is_power_of_2 return whether a number is a power of 2"_test = [] {
        using alx::is_power_of_2;

        expect(not is_power_of_2(0u));
        expect(is_power_of_2(1u));

        for (int i = 1; i < 4; i++) expect(is_power_of_2(1u << i));

        expect(not is_power_of_2(5u));
        expect(not is_power_of_2(17u));
        expect(not is_power_of_2(25u));
    };
}
