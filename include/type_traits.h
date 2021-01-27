#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H

namespace alx {

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
        static constexpr bool value{false};
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

    template<>
    struct is_integral<bool> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<char8_t> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<char16_t> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<char32_t> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<wchar_t> {
        static constexpr bool value{true};
    };

    template<>
    struct is_integral<char> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<short> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<int> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<long> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<long long> {
        static constexpr bool value{true};
    };

    template<>
    struct is_integral<unsigned char> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<unsigned short> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<unsigned int> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<unsigned long> {
        static constexpr bool value{true};
    };
    template<>
    struct is_integral<unsigned long long> {
        static constexpr bool value{true};
    };

    template<>
    struct is_integral<signed char> {
        static constexpr bool value{true};
    };

    template<typename T>
    constexpr bool is_integral_v = is_integral<T>::value;

    // is_arithmetic is either an integral or a floating point type.

    template<typename T>
    struct is_arithmetic {
        static constexpr bool value{is_integral_v<T>};
    };
    template<>
    struct is_arithmetic<float> {
        static constexpr bool value{true};
    };
    template<>
    struct is_arithmetic<double> {
        static constexpr bool value{true};
    };
    template<>
    struct is_arithmetic<long double> {
        static constexpr bool value{true};
    };

    template<typename T>
    constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

    template<typename T, bool = is_arithmetic_v<T>>
    struct is_signed {
        static constexpr bool value{T{-1} < T{0}};
    };

    template<>
    struct is_signed<unsigned char> {
        static constexpr bool value{false};
    };
    template<>
    struct is_signed<unsigned short> {
        static constexpr bool value{false};
    };
    template<>
    struct is_signed<unsigned int> {
        static constexpr bool value{false};
    };
    template<>
    struct is_signed<unsigned long> {
        static constexpr bool value{false};
    };
    template<>
    struct is_signed<unsigned long long> {
        static constexpr bool value{false};
    };

    template<typename T>
    struct is_signed<T, false> {
        static constexpr bool value{false};
    };

    template<typename T>
    constexpr bool is_signed_v = is_signed<T>::value;

} // namespace alx

#endif
