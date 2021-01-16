#ifndef UTILITY_H
#define UTILITY_H

#include "type_traits.h"

namespace alx {

    template<typename T> [[nodiscard]] constexpr remove_ref_t<T> && move(T && t) noexcept {
        return static_cast<remove_ref_t<T> &&>(t);
    }

    template<typename T> [[nodiscard]] constexpr T && forward(remove_ref_t<T> & t) noexcept {
        return static_cast<T &&>(t);
    }

    template<typename T, typename U = T>
    [[nodiscard]] constexpr T exchange(T & obj, U && new_value) {
        auto old_value = move(obj);
        obj = forward<U>(new_value);
        return old_value;
    }

    template<typename T> constexpr void swap(T & lhs, T & rhs) { lhs = exchange(rhs, move(lhs)); }

} // namespace alx

#endif
