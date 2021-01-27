#ifndef BIT_MANIP_H
#define BIT_MANIP_H

namespace alx {

    template<typename T>
    constexpr int popcount(T x) noexcept {
        int count = 0;
        for (; x != 0; count++) x &= x - 1;
        return count;
    }
} // namespace alx

#endif
