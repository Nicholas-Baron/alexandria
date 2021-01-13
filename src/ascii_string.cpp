#include <ascii_string.h>

#include <stdlib.h>
#include <string.h>
#include <utility.h>

namespace alx {
    ascii_string & ascii_string::append(const ascii_string & input) noexcept {

        const auto final_size = input.size_ + this->size_;
        const auto final_capacity = input.capacity_ + this->capacity_;
        auto * const final_buf = strcpy(new char[final_capacity], this->buf);

        delete[] buf;

        this->buf = strcat(final_buf, input.buf);
        this->capacity_ = final_capacity;
        this->size_ = final_size;

        return *this;
    }

    ascii_string & ascii_string::operator+=(char c) noexcept {
        const auto final_size = this->size_ + 1;
        const auto final_capacity = this->capacity_ + 1;
        auto * const final_buf = strcpy(new char[final_capacity], this->buf);

        delete[] buf;

        // insert the char at the end
        final_buf[size_] = c;
        final_buf[final_size] = '\0';

        this->buf = final_buf;
        this->capacity_ = final_capacity;
        this->size_ = final_size;

        return *this;
    }

    ascii_string::ascii_string(const char * input) noexcept
        : size_{strlen(input)}
        , capacity_{size_ + 1}
        , buf{strcpy(new char[capacity_], input)} {}

    ascii_string::ascii_string(const ascii_string & input) noexcept
        : size_{input.size_}
        , capacity_{input.size_ + 1}
        , buf{strcpy(new char[capacity_], input.buf)} {}

    ascii_string::ascii_string(ascii_string && input) noexcept
        : size_{exchange(input.size_, 0)}
        , capacity_{exchange(input.capacity_, 0)}
        , buf{exchange(input.buf, nullptr)} {}

    ascii_string & ascii_string::operator=(const ascii_string & input) noexcept {
        size_ = input.size_;
        capacity_ = input.capacity_;

        delete[] buf;

        buf = strcpy(new char[capacity_], input.buf);

        return *this;
    }

} // namespace alx
