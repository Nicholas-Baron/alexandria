#include "file_input.h"

#include <boost_ut/ut.hpp>

int main() {
    using namespace boost::ut;

    "attempting to read a non-existent file returns an empty optional"_test = [] {
        auto result = alx::read_entire_file("abcdefg");
        expect(not result.has_value());
    };
}
