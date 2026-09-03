#include <numrecipes/util.h>

/*
 * nrerror() is documented to print a runtime error message and exit the
 * program with a non-zero status. This test intentionally triggers that
 * behavior; ctest is configured (see tests/CMakeLists.txt) to expect the
 * failing exit code and the error message on stderr.
 */
int main(void) {
    nrerror("intentional test error from test_util");

    /* unreachable */
    return 0;
}
