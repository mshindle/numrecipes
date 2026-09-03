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
