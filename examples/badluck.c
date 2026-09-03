/*
 * Find the date on which Friday the 13th is a full moon.
 *
 * For GMT -5.0, the dates (yyyy-mm-dd) are between 1900 and 2050...
 * 1903/03/13, 1905/10/13, 1919/06/13, 1922/01/13, 1970/11/13, 1987/02/13,
 * 2000/10/13, 2019/09/13, and 2049/08/13.
 */
#include <stdio.h>
#include "numrecipes/misc.h"

#define ZON (-5.0) // Eastern Standard Time
#define YEAR_BEGIN 1970
#define YEAR_END 2050

int main(void) {
    int n;
    long jd;
    double timzon = ZON / 24.0, frac;

    printf("Full moons on Friday the 13th from %5d to %5d\n", YEAR_BEGIN, YEAR_END);
    // loop over each year
    for (int year = YEAR_BEGIN; year <= YEAR_END; year++) {
        // and loop over each month
        for (int month = 1; month <= 12; month++) {
            long jday = juliandate(year, month, 13);
            enum weekday idwk = (enum weekday) ((jday + 1) % 7);
            if (idwk == FRIDAY) {
                /* The value n is a first approximation to how many full moons have occurred since 1900. We will feed it
                 * into the phase routine & adjust it up or down until we determine our desired 13th was or was
                 * not a full moon. The variable icon signals direction of adjustment. */
                n = (int) (12.37 * (year - 1900 + (month - 0.5) / 12.0));
                int icon = 0;
                for (;;) {
                    // get date of full moon n
                    moon_phase(n, FULL_MOON, &jd, &frac);
                    // convert to hours in correct timezone
                    frac = 24.0 * (frac + timzon);
                    // convert from Julian Days beginning at noon to
                    // civil days beginning at midnight
                    if (frac < 0.0) {
                        --jd;
                        frac += 24.0;
                    }
                    if (frac > 12.0) {
                        ++jd;
                        frac -= 12.0;
                    } else {
                        frac += 12.0;
                    }
                    // did we hit our target day?
                    if (jd == jday) {
                        printf("\n%4d/%02d/%02d\n", year, month, 13);
                        printf("%s %5.1f %s %2.1f %s\n", "Full moon", frac, "hrs after midnight", ZON, "GMT");
                        break;
                    }
                    int ic = (jday >= jd) ? 1 : -1;
                    if (ic == (-icon)) break;
                    icon = ic;
                    n += ic;
                }
            }
        }
    }

    return 0;
}
