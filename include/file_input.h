#ifndef FILE_INPUT_H
#define FILE_INPUT_H

#include "ascii_string.h"
#include "optional.h"

namespace alx {
    [[nodiscard]] optional<ascii_string> read_entire_file(const ascii_string &) noexcept;
}

#endif
