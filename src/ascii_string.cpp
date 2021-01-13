#include <ascii_string.h>

#include <stdlib.h>
#include <string.h>
#include <utility.h>

namespace alx {
    ascii_string & ascii_string::append(const ascii_string & input) noexcept {

        const auto final_size = input.size_ + this->size_;
        auto * const final_buf = strcpy(new char[final_size + 1], this->buf);

        delete[] buf;

        this->buf = strcat(final_buf, input.buf);
        this->size_ = final_size;

        return *this;
    }

    ascii_string & ascii_string::operator+=(char c) noexcept {
        const auto final_size = this->size_ + 1;
        auto * const final_buf = strcpy(new char[final_size + 1], this->buf);

        delete[] buf;

        // insert the char at the end
        char * iter = final_buf;
        while (*iter != '\0') iter++;
        *iter = c;
        *(iter + 1) = '\0';

        this->buf = final_buf;
        this->size_ = final_size;

        return *this;
    }

    ascii_string::ascii_string(const char * input) noexcept
        : size_{strlen(input)}
        , buf{strcpy(new char[size_ + 1], input)} {}

    ascii_string::ascii_string(const ascii_string & input) noexcept
        : size_{input.size_}
        , buf{strcpy(new char[size_ + 1], input.buf)} {}

    ascii_string::ascii_string(ascii_string && input) noexcept
        : size_{exchange(input.size_, 0)}
        , buf{exchange(input.buf, nullptr)} {}

    ascii_string & ascii_string::operator=(const ascii_string & input) noexcept {
        size_ = input.size_;

        delete[] buf;

        buf = strcpy(new char[size_ + 1], input.buf);

        return *this;
    }

} // namespace alx
