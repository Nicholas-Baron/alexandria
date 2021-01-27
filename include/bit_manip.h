#ifndef BIT_MANIP_H
#define BIT_MANIP_H

#include "concepts.h"

namespace alx {

    template<typename T>
    constexpr int popcount(T x) noexcept {
        int count = 0;
        for (; x != 0; count++) x &= x - 1;
        return count;
    }

    // clang-format off
    template<unsigned_integral T>
    requires(not same_as<T, bool>
            and not same_as<T, char>
            and not same_as<T, char8_t>
            and not same_as<T, char16_t>
            and not same_as<T, char32_t>
            and not same_as<T, wchar_t>)
    constexpr bool is_power_of_2(T x) noexcept {
        return popcount(x) == 1;
    }
    // clang-format on

} // namespace alx

#endif
