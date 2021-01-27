#include "type_aliases.h"

#include "type_traits.h"

int main() {

    static_assert(alx::is_same_v<alx::u8, unsigned char>);

    static_assert(alx::is_same_v<alx::i32, int>);
}
