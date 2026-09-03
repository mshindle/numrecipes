# Miscellaneous numerical routines

The miscellaneous numerical routines are declared in:
```c
#include <numrecipes/misc.h>
```
This group contains standalone numerical algorithms and helper functions that do not belong to a larger specialized category.

## Current routines

### `moon_phase`
```c
void moon_phase(int n, int nph, long *jd, double *frac);
```
Calculates the Julian day number and fractional part of the day for a requested moon phase.

The phase argument `nph` selects the desired phase:

| `nph` | Phase |
|---:|---|
| `0` | New moon |
| `1` | First quarter |
| `2` | Full moon |
| `3` | Last quarter |

The function returns:

- The Julian day number through `jd`
- The fractional part of the day through `frac`

### `gcd`
```c
long gcd(long a, long b);
```
Returns the greatest common divisor of two integer values.

## Planned routines

Possible future routines include:

- Julian day conversions
- Calendar date conversions
- Least common multiple
- Integer power helpers
- Angle conversion helpers
- Other standalone numerical utilities
