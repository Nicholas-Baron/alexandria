#ifndef CONCEPTS_H
#define CONCEPTS_H

#include "type_traits.h"

namespace alx {

    template<typename T, typename U> concept same_as = is_same_v<T, U>;

    template<typename T> concept integral = is_integral_v<T>;

    template<typename T> concept signed_integral = integral<T> and is_signed_v<T>;

    template<typename T> concept unsigned_integral = integral<T> and not signed_integral<T>;
} // namespace alx

#endif
