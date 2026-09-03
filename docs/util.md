# Utility routines

The utility routines are declared in:
```c
#include <numrecipes/util.h>
```
This group contains support routines used throughout the library.

## Current routines

### `nrerror`
```c
void nrerror(char error_text[]);
```
Prints a runtime error message and exits the program.

## Planned routines

Utility routines should include allocation and cleanup helpers for common numerical data structures.

Planned helpers include:
```c
float *vector(long nl, long nh);
int *ivector(long nl, long nh);
double *dvector(long nl, long nh);

float **matrix(long nrl, long nrh, long ncl, long nch);
double **dmatrix(long nrl, long nrh, long ncl, long nch);

void free_vector(float *v, long nl, long nh);
void free_ivector(int *v, long nl, long nh);
void free_dvector(double *v, long nl, long nh);

void free_matrix(float **m, long nrl, long nrh, long ncl, long nch);
void free_dmatrix(double **m, long nrl, long nrh, long ncl, long nch);
```
These routines may follow the traditional Numerical Recipes indexing style, where arrays can be indexed from a caller-specified lower bound through an upper bound.

## Notes

All memory allocated by utility allocation routines should have a matching free routine.
