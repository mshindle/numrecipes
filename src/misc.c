#include <numrecipes/misc.h>

#include <math.h>
#include <numrecipes/util.h>

/*
 * This routine calculates the phases of the moon. Given an integer N and a code
 * NPH for the phase desired (nph = 0 for new moon, 1 for first quarter, 2 for full moon,
 * 3 for last quarter), the routine returns the Julian Day number (jd) and the fractional
 * part of the day (frac) to be added to it, of the nth such phase since January 1900.
 * GMT is assumed.
 */
void moon_phase(int n, int nph, long *jd, double *frac) {
    double am, as, c, t, t2, xtra;

    c = n + (nph/4.0);
    t = c/1236.85;
    t2 = t*t;
    as = 359.2242 + 29.10535608 * c;
    am = 306.0253 + 385.81691806 * c + 0.010730 * t2;
    *jd = 2415020 + 28L*n + 7L*nph;
    xtra = 0.75933+1.53058868*c+((1.178e-4)-(1.55e-7)*t)*t2;

    if (nph == 0 || nph == 2) {
        xtra += (0.1734-3.93e-4*t) * sin(RAD*as)-0.4068*sin(RAD*am);
    } else if (nph == 1 || nph == 3) {
        xtra += (0.1721-4.0e-4*t) * sin(RAD*as)-0.6280*sin(RAD*am);
    } else {
        nrerror("nph is invalid value in moon_phase()");
    }

    const long i = (long) (xtra >= 0.0 ? floor(xtra) : ceil(xtra - 1.0));
    *jd += i;
    *frac = xtra - (double)i;
}

/*
 * juliandate returns the julian day number that begins at noon of the calendar date specified by year, month, and day.
 * Positive year signifies AD, negative year signifies BC. Remember tha the year after 1 BC was 1 AD.
 */
#define GREGORIAN_CUTOFF 588829L  // (15+31L*(10+12L*1582))
long juliandate(const int year, const int month, const int day) {
    long jy = year, jm;
    
    if (jy == 0) nrerror("juliandate: there is no zero year");
    if (jy < 0) jy++;
    if (month > 2) {
        jm = month + 1;
    } else {
        --jy;
        jm=month+13;
    }
    long jul = (long) (floor(365.25 * (double) jy) + floor(30.6001 * (double) jm) + day + 1720995);
    if (day + 31L * (month+12L*year) >= GREGORIAN_CUTOFF) {
        const long ja = (long) (0.01 * (double) jy);
        jul += 2L-ja+(long)(0.25*(double)ja);
    }

    return jul;
}

/*
 * gcd returns the greatest common divisor of a and b.
 */
long gcd(long a, long b) {
    if (a < 0) {
        a = -a;
    }

    if (b < 0) {
        b = -b;
    }

    while (b != 0) {
        const long t = b;
        b = a % b;
        a = t;
    }

    return a;
}
