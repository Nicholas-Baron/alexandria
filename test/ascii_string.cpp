#include "ascii_string.h"

#include <boost_ut/ut.hpp>

#include <string.h>
#include <utility.h> // alx::move

using alx::string;

int main() {
    using namespace boost::ut;

    "a string is initially empty"_test = [] {
        string str;
        expect(str.empty());
    };

    "strlen of c_str and size() agree"_test = [] {
        const string hello = "hello";
        expect(eq(strlen(hello.c_str()), hello.size()));
    };

    "the length of 'hello' is 5"_test = [] {
        const string hello = "hello";
        expect(hello.size() == 5_ul);
    };

    "a string can be equal to a char *"_test = [] {
        const string world = "world";
        expect(world == "world");
    };

    "a string will be equal with itself"_test = [] {
        const string world = "world";
        expect(world == world);
    };

    "appending changes the string contents"_test = [] {
        string hello = "hello";
        const auto old_hello = hello;
        hello += '!';
        expect(old_hello != hello);
    };

    "a moved-from string is empty"_test = [] {
        string hello = "hello";
        string new_hello = alx::move(hello);
        expect(hello.empty());
        expect(new_hello == "hello");
    };

    "a empty string is equal to the empty char *"_test = [] {
        string str;
        expect(str == "");
    };
}
