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

        size_t size_{0};
        char * buf{nullptr};
    };

    using string = alx::ascii_string;

} // namespace alx

#endif
