# numrecipes

`numrecipes` is a C library containing reusable numerical algorithms and utility routines.

The goal of the project is to provide a small, organized collection of numerical routines that can be easily integrated into other C projects.

## Library groups

The library is organized into the following groups.

### Miscellaneous numerical routines

Header:
```c
#include <numrecipes/misc.h>
```
This group contains standalone numerical routines that do not belong to a larger specialized category.

Examples include:

- Moon phase calculations
- Julian day conversions
- Greatest common divisor
- Calendar and date helpers
- Other general numerical utilities

See [docs/misc.md](docs/misc.md).

### Linear algebra routines

Header:
```c
#include <numrecipes/linalg.h>
```
This group contains algorithms for solving systems of linear algebraic equations.

Planned examples include:

- Gaussian elimination
- LU decomposition
- Forward substitution
- Back substitution
- Matrix-based linear system solvers
- Iterative solvers

See [docs/linalg.md](docs/linalg.md).

### Utility routines

Header:
```c
#include <numrecipes/util.h>
```
This group contains helper routines used by the rest of the library.

Examples include:

- Runtime error handling
- Vector allocation
- Matrix allocation
- Freeing vectors and matrices
- Other memory-management helpers

See [docs/util.md](docs/util.md).

## Project structure
```text
numrecipes/
├── CMakeLists.txt
├── README.md
├── docs/
│   ├── misc.md
│   ├── linalg.md
│   └── util.md
├── include/
│   └── numrecipes/
│       ├── misc.h
│       ├── linalg.h
│       └── util.h
└── src/
    ├── misc.c
    ├── linalg.c
    └── util.c
```
## Building

Use CMake to configure and build the project.
```bash
cmake -S . -B build
cmake --build build
```
By default, the project builds the `numrecipes` library.

## Building a static or shared library

The project respects the standard CMake `BUILD_SHARED_LIBS` option.

To build a static library:
```bash
cmake -S . -B build-static -DBUILD_SHARED_LIBS=OFF
cmake --build build-static
```
To build a shared library:
```bash
cmake -S . -B build-shared -DBUILD_SHARED_LIBS=ON
cmake --build build-shared
```
## Installing

Install with:
```bash
cmake --install build
```
To install into a custom prefix:
```bash
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=$HOME/.local
cmake --build build
cmake --install build
```
This installs the public headers under:
```text
include/numrecipes/
```
and the library under the platform-specific library directory, such as:
```text
lib/
```
## Using numrecipes from another CMake project

After installation, another CMake project can use:
```cmake
find_package(numrecipes CONFIG REQUIRED)

add_executable(my_program main.c)

target_link_libraries(my_program PRIVATE numrecipes::numrecipes)
```
Then include headers from C code:
```c
#include <numrecipes/misc.h>
#include <numrecipes/linalg.h>
#include <numrecipes/util.h>
```
## Example
```c
#include <stdio.h>

#include <numrecipes/misc.h>

int main(void)
{
    long jd;
    double frac;

    moon_phase(0, 2, &jd, &frac);

    printf("Julian day: %ld\n", jd);
    printf("Fractional day: %f\n", frac);

    return 0;
}
```
## Documentation

More detailed documentation is available in the `docs/` directory:

- [Miscellaneous routines](docs/misc.md)
- [Linear algebra routines](docs/linalg.md)
- [Utility routines](docs/util.md)

## License

Add license information here.
