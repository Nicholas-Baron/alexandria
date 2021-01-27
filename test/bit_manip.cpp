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
}
