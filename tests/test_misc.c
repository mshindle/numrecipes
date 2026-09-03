#include <numrecipes/misc.h>

#include <assert.h>

int main(void) {
    assert(gcd(12, 18) == 6);
    assert(gcd(-12, 18) == 6);
    assert(gcd(0, 5) == 5);
    assert(gcd(7, 7) == 7);

    long jd;
    double frac;

    moon_phase(0, 2, &jd, &frac);
    assert(jd > 0);
    assert(frac >= 0.0 && frac < 1.0);

    return 0;
}
