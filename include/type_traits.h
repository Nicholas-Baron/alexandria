#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H

namespace alx {

    template<typename T> struct remove_ref { using type = T; };
    template<typename T> struct remove_ref<T &> { using type = T; };
    template<typename T> struct remove_ref<T &&> { using type = T; };

    template<typename T> using remove_ref_t = typename remove_ref<T>::type;

} // namespace alx

#endif
