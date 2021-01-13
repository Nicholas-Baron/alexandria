
#include "type_traits.h"

int main() {
    // This test suite is unique as it is mostly compile time.

    static_assert(alx::is_same_v<int, int>);
    static_assert(not alx::is_same_v<int, bool>);
}
