#ifndef ASCII_STRING_H
#define ASCII_STRING_H

#include <stddef.h>
#include <string.h>

namespace alx {
    class ascii_string final {
      public:
        // Manipulations

        [[nodiscard]] constexpr const char * c_str() const noexcept { return buf; }

        ascii_string & append(const ascii_string & input) noexcept;

        ascii_string & operator+=(const ascii_string & input) noexcept { return append(input); }

        ascii_string & operator+=(char) noexcept;

        [[nodiscard]] constexpr size_t size() const noexcept { return size_; }

        [[nodiscard]] constexpr bool empty() const noexcept { return size() == 0; }

        // Creations
        constexpr ascii_string() noexcept = default;

        [[nodiscard]] ascii_string(const char * input) noexcept;

        ascii_string(const ascii_string & input) noexcept;

        ascii_string(ascii_string && input) noexcept;

        ascii_string & operator=(const ascii_string & input) noexcept;

        ~ascii_string() noexcept { delete[] buf; }

      private:
        // Comparisons where both sides are strings
        [[nodiscard]] friend constexpr bool operator==(const ascii_string & lhs,
                                                       const ascii_string & rhs) noexcept {
            if (lhs.buf == nullptr or rhs.buf == nullptr) return lhs.buf == rhs.buf;
            if (lhs.size_ != rhs.size_) return false;
            return strcmp(lhs.buf, rhs.buf) == 0;
        }

        [[nodiscard]] friend constexpr bool operator!=(const ascii_string & lhs,
                                                       const ascii_string & rhs) noexcept {
            return not(lhs == rhs);
        }

        // Comparisons where the right hand side is a char *
        [[nodiscard]] friend constexpr bool operator==(const ascii_string & lhs,
                                                       const char * rhs) noexcept {
            if (lhs.buf == nullptr or rhs == nullptr) {
                // Here, the lhs or the rhs (possibly both) is null.
                if (lhs.buf == rhs) return true;

                // Here, the lhs xor the rhs is null.

                if (lhs.buf != nullptr) return strlen(lhs.buf) == 0;
                else
                    return strlen(rhs) == 0;
            }

            return strcmp(lhs.buf, rhs) == 0;
        }

        [[nodiscard]] friend constexpr bool operator!=(const ascii_string & lhs,
                                                       const char * rhs) noexcept {
            return not(lhs == rhs);
        }

        // Data members
        size_t size_{0};
        size_t capacity_{0};
        char * buf{nullptr};
    };

    using string = alx::ascii_string;

} // namespace alx

#endif
