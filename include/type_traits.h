#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H

namespace alx {

    template<typename T, typename U> struct is_same { static constexpr bool value{false}; };
    template<typename T> struct is_same<T, T> { static constexpr bool value{true}; };

    template<typename T, typename U> constexpr bool is_same_v = is_same<T, U>::value;

    template<typename T> struct remove_ref { using type = T; };
    template<typename T> struct remove_ref<T &> { using type = T; };
    template<typename T> struct remove_ref<T &&> { using type = T; };

    template<typename T> using remove_ref_t = typename remove_ref<T>::type;

} // namespace alx

#endif
