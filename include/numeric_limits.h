#ifndef NUMERIC_LIMITS_H
#define NUMERIC_LIMITS_H

#include <limits.h>

namespace alx {
    template<typename T>
    struct numeric_limits {
        static constexpr bool is_specialized{false};
        static constexpr bool is_signed{false};
        static constexpr bool is_integer{false};
        static constexpr bool is_exact{false};
    };

#define NUM_LIM_INST(TYPE, HAS_SIGN, IS_INT, EXACT)                                                \
    template<>                                                                                     \
    struct numeric_limits<TYPE> {                                                                  \
        static constexpr bool is_specialized{true};                                                \
        static constexpr bool is_signed{HAS_SIGN};                                                 \
        static constexpr bool is_integer{IS_INT};                                                  \
        static constexpr bool is_exact{EXACT};                                                     \
    }

    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(char, CHAR_MIN < 0, true, true);
    NUM_LIM_INST(signed char, true, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);
    NUM_LIM_INST(bool, false, true, true);

#undef NUM_LIM_INST
} // namespace alx

#endif
