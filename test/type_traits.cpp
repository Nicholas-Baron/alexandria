
#include "type_traits.h"

int main() {
    // This test suite is unique as it is mostly compile time.

    // is_same is true if two types are exactly the same.
    static_assert(alx::is_same_v<int, int>);

    // is_same is false if two types are not exactly the same.
    static_assert(not alx::is_same_v<int, bool>);

    // remove_ref removes lvalue references.
    static_assert(alx::is_same_v<alx::remove_ref_t<int &>, int>);

    // remove_ref removes rvalue references.
    static_assert(alx::is_same_v<alx::remove_ref_t<int &&>, int>);

    // remove_ref returns the type if there are no references to be removed.
    static_assert(alx::is_same_v<alx::remove_ref_t<int>, int>);
}
