#ifndef ASSERTS_H
#define ASSERTS_H

#include <stdio.h>
#include <stdlib.h>

#define assert(cond)                                                                               \
    if (not(cond)) do {                                                                            \
            printf("%s:%d condition " #cond " failed.\n", __FILE__, __LINE__);                     \
            exit(-365);                                                                            \
    } while (false)

#define assert_eq(lhs, rhs) assert(lhs == rhs)

#define assert_ne(lhs, rhs) assert(lhs != rhs)

#define unreachable()                                                                              \
    do {                                                                                           \
        printf("%s:%d was marked unreachable.\n", __FILE__, __LINE__);                             \
        exit(-365);                                                                                \
    } while (false)

#define todo()                                                                                     \
    do {                                                                                           \
        printf("%s:%d is not implemented yet.\n", __FILE__, __LINE__);                             \
        exit(-365);                                                                                \
    } while (false)

#endif
