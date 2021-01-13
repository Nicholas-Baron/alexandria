# Alexandria: A C++ "standard library"
## Philosophy
This library follows the C++ philosophy of "you do not pay for what you do not use".
To that end, the following are design principles the library uses:
 * Allocation failure is terminal: Most C++ programs are not designed to handle Out-Of-Memory (OOM) issues, yet this is a major reason the C++ standard library is not `noexcept` a majority of the time.
 * Simplicity over customization: The standard library has many "customization points" which few programs use, but increase the inherent complexity of implementation.

## What this library is not
 * A testing ground for C++ standards proposals
 * A Swiss Army knife for every conceivable C++ program

## Dependencies
These are the external dependencies bundled in this repository:
 * [boost-ext/ut](https://github.com/boost-ext/ut) as a single header for testing
 * [clang-format cmake integration](https://github.com/zemasoft/clangformat-cmake)

This is a possible future dependency:
 * [fmtlib](https://github.com/fmtlib/fmt) as three header files to handle printing
