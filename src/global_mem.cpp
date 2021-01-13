#include <cstdlib>

[[nodiscard]] void * operator new(size_t size) {
    void * ptr = malloc(size);
    if (ptr == nullptr) {
        exit(-256);
    } else
        return ptr;
}

/*
[[nodiscard]] void * operator new(size_t size, std::align_val_t al) {
    void * ptr = aligned_alloc(static_cast<size_t>(al), size);
    if (ptr == nullptr) {
        exit(-256);
    } else
        return ptr;
}
*/

[[nodiscard]] void * operator new[](size_t size) {
    void * ptr = malloc(size);
    if (ptr == nullptr) {
        exit(-256);
    } else
        return ptr;
}

void operator delete(void * ptr) noexcept { free(ptr); }
void operator delete(void * ptr, size_t) noexcept { free(ptr); }

void operator delete[](void * ptr) noexcept { free(ptr); }
void operator delete[](void * ptr, size_t) noexcept { free(ptr); }
