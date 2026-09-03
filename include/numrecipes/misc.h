#ifndef NUMRECIPES_MISC_H
#define NUMRECIPES_MISC_H

#define RAD (3.14159265358979323846 / 180.0)

enum weekday {
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

enum moon_phase_kind {
    NEW_MOON = 0,
    FIRST_QUARTER,
    FULL_MOON,
    LAST_QUARTER
};

void moon_phase(int n, int nph, long *jd, double *frac);
long juliandate(int year, int month, int day);
long gcd(long a, long b);

#endif // NUMRECIPES_MISC_H
