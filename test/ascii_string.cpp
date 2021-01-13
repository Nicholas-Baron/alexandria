#include "ascii_string.h"

#include <boost_ut/ut.hpp>

#include <stdio.h>
#include <string.h>

using alx::string;

static void print(string test) { puts(test.c_str()); }

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
        expect(eq(hello.size(), 5ul));
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
}
