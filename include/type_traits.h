#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H

#include "numeric_limits.h"

namespace alx {

    // trait to check if two traits are the same.

    template<typename T, typename U>
    struct is_same {
        static constexpr bool value{false};
    };
    template<typename T>
    struct is_same<T, T> {
        static constexpr bool value{true};
    };

    template<typename T, typename U>
    constexpr bool is_same_v = is_same<T, U>::value;

    // trait to add references onto a given type.

    template<typename T>
    struct add_lval_ref {
        using type = T &;
    };

    template<typename T>
    struct add_rval_ref {
        using type = T &&;
    };

    template<typename T>
    using add_lval_ref_t = typename add_lval_ref<T>::type;

    template<typename T>
    using add_rval_ref_t = typename add_rval_ref<T>::type;

    // trait to remove references from a given type.

    template<typename T>
    struct remove_ref {
        using type = T;
    };
    template<typename T>
    struct remove_ref<T &> {
        using type = T;
    };
    template<typename T>
    struct remove_ref<T &&> {
        using type = T;
    };

    template<typename T>
    using remove_ref_t = typename remove_ref<T>::type;

    // Type traits for numeric types

    template<typename T>
    struct is_integral {
        static constexpr bool value{numeric_limits<T>::is_integer};
    };
    template<typename T>
    struct is_integral<const T> {
        static constexpr bool value{is_integral<T>::value};
    };
    template<typename T>
    struct is_integral<volatile T> {
        static constexpr bool value{is_integral<T>::value};
    };
    template<typename T>
    struct is_integral<const volatile T> {
        static constexpr bool value{is_integral<T>::value};
    };

    template<typename T>
    constexpr bool is_integral_v = is_integral<T>::value;

    // is_arithmetic is either an integral or a floating point type.

    template<typename T>
    struct is_arithmetic {
        static constexpr bool value{numeric_limits<T>::is_specialized};
    };

    template<typename T>
    constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

    template<typename T, bool = is_arithmetic_v<T>>
    struct is_signed {
        static constexpr bool value{numeric_limits<T>::is_signed};
    };

    template<typename T>
    constexpr bool is_signed_v = is_signed<T>::value;

} // namespace alx

#endif
