#include "file_input.h"

#include <stdio.h>
#include <strings.h>

namespace alx {

    optional<ascii_string> read_entire_file(const ascii_string & filename) noexcept {

        auto * file = fopen(filename.c_str(), "r");
        if (file == nullptr) {
            perror("fopen");
            return {};
        }

        ascii_string result;

        {
            static constexpr auto buffer_size = 256;
            char buffer[buffer_size];
            bzero(buffer, buffer_size);

            // Loop and read in all the file
            while (not feof(file) and not ferror(file)) {
                auto nread = fread(buffer, 1, buffer_size, file);
                result += buffer;
                bzero(buffer, nread);
            }
        }

        if (fclose(file) != 0) { perror("fclose"); }

        return result;
    }
} // namespace alx
