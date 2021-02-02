
#include "type_traits.h"

int main() {
    // This test suite is unique as it is mostly compile time.

    // is_same is true if two types are exactly the same.
    static_assert(alx::is_same_v<int, int>);

    // is_same is false if two types are not exactly the same.
    static_assert(not alx::is_same_v<int, bool>);

    // add_lval_ref adds an lvalue reference.
    static_assert(alx::is_same_v<alx::add_lval_ref_t<int>, int &>);

    // add_lval_ref of a lvalue ref is the same as the input.
    static_assert(alx::is_same_v<alx::add_lval_ref_t<int &>, int &>);

    // add_rval_ref adds an rvalue reference.
    static_assert(alx::is_same_v<alx::add_rval_ref_t<int>, int &&>);

    // add_rval_ref of a rvalue raf is the same as the input.
    static_assert(alx::is_same_v<alx::add_rval_ref_t<int &&>, int &&>);

    // remove_ref removes lvalue references.
    static_assert(alx::is_same_v<alx::remove_ref_t<int &>, int>);

    // remove_ref removes rvalue references.
    static_assert(alx::is_same_v<alx::remove_ref_t<int &&>, int>);

    // remove_ref returns the type if there are no references to be removed.
    static_assert(alx::is_same_v<alx::remove_ref_t<int>, int>);

    // The normal int type is signed.
    static_assert(alx::is_signed_v<int>);

    // The normal int type is arithmetic.
    static_assert(alx::is_arithmetic_v<int>);

    // The normal int type is an integral type.
    static_assert(alx::is_integral_v<int>);

    // The unsigned type is not signed.
    static_assert(not alx::is_signed_v<unsigned>);

    // The unsigned type is an integral.
    static_assert(alx::is_integral_v<unsigned>);
}
