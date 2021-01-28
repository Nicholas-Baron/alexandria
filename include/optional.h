#ifndef OPTIONAL_H
#define OPTIONAL_H

#include "asserts.h"
#include "utility.h"

namespace alx {
    template<typename T>
    class optional final {
      public:
        constexpr optional() noexcept = default;

        constexpr optional(T && value) {
            new (buffer) T{move(value)};
            alive = true;
        }

        constexpr optional(const T & value)
            : optional(T{value}) {}

        template<typename... Args>
        constexpr explicit optional(Args &&... args)
            : optional(T{forward<Args>(args)...}) {}

        constexpr ~optional() noexcept { reset(); }

        [[nodiscard]] constexpr bool has_value() const noexcept { return alive; }

        constexpr void reset() {
            if (not alive) return;

            value().T::~T();
            alive = false;
        }

        constexpr T release_value() noexcept {
            assert(has_value());
            auto result = move(value());
            reset();
            return result;
        }

        // Value accessors

        constexpr T & value() & noexcept {
            assert(has_value());
            return *value_ptr();
        }

        constexpr const T & value() const & noexcept {
            assert(has_value());
            return *value_ptr();
        }

        constexpr T && value() && noexcept {
            assert(has_value());
            return *value_ptr();
        }

        constexpr const T && value() const && noexcept {
            assert(has_value());
            return *value_ptr();
        }

        constexpr const T * operator->() const noexcept { return value_ptr(); }

        constexpr T * operator->() noexcept { return value_ptr(); }

      private:
        // Two helpers to access the value as a ptr.

        [[nodiscard]] constexpr T * value_ptr() noexcept { return reinterpret_cast<T *>(buffer); }

        [[nodiscard]] constexpr const T * value_ptr() const noexcept {
            return reinterpret_cast<const T *>(buffer);
        }

        alignas(T) char buffer[sizeof(T)];
        bool alive{false};
    };

} // namespace alx

#endif
