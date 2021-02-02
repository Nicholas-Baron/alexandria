#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include "asserts.h"
#include "type_traits.h"
#include "utility.h"

namespace alx {
    template<typename T>
    class unique_ptr final {
      public:
        constexpr unique_ptr() noexcept = default;

        explicit constexpr unique_ptr(T * raw_ptr) noexcept
            : ptr{raw_ptr} {}

        unique_ptr(const unique_ptr &) = delete;
        unique_ptr & operator=(const unique_ptr &) = delete;

        unique_ptr(unique_ptr && src) noexcept
            : ptr{exchange(src.ptr, nullptr)} {}

        unique_ptr & operator=(unique_ptr && src) noexcept {
            ptr = exchange(src.ptr, nullptr);
            return *this;
        }

        ~unique_ptr() noexcept { delete ptr; }

        using reference = add_lval_ref_t<T>;
        using pointer = T *;

        reference operator*() noexcept {
            assert_ne(ptr, nullptr);
            return *ptr;
        }

        pointer operator->() noexcept {
            assert_ne(ptr, nullptr);
            return ptr;
        }

        [[nodiscard]] friend bool operator==(const unique_ptr<T> & lhs, T * rhs) noexcept {
            return lhs.ptr == rhs;
        }

        [[nodiscard]] friend bool operator==(T * lhs, const unique_ptr<T> & rhs) noexcept {
            return lhs == rhs.ptr;
        }

        [[nodiscard]] friend bool operator==(const unique_ptr<T> & lhs,
                                             const unique_ptr<T> & rhs) noexcept {
            return false;
        }

      private:
        pointer ptr{nullptr};
    };

    template<typename T, typename... Args>
    unique_ptr<T> make_unique(Args &&... args) {
        return unique_ptr{new T{forward<Args>(args)...}};
    }
} // namespace alx

#endif
