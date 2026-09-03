# Linear algebra routines

The linear algebra routines are declared in:
```c
#include <numrecipes/linalg.h>
```
This group contains algorithms for solving systems of linear algebraic equations and related matrix operations.

## Planned routines

Initial planned algorithms include:

- Gaussian elimination
- Gauss-Jordan elimination
- LU decomposition
- Forward substitution
- Back substitution
- Matrix-based linear system solvers
- Iterative linear solvers

## Expected usage style

Linear algebra routines should use the allocation helpers from:
```c
#include <numrecipes/util.h>
```
where appropriate.

For example, matrix and vector allocation routines should live in the utility module, while equation-solving algorithms should live in the linear algebra module.

## Notes

The exact function APIs for this section are still being defined.
