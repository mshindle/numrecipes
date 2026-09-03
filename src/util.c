//
// Created by mshindle on 9/2/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <numrecipes/util.h>

#define NR_END 1
#define FREE_ARG char*

// numerical recipes standard error handler
void nrerror(char error_text[])
{
    fprintf(stderr, "Numerical Recipes run-time error...\n");
    fprintf(stderr, "%s\n", error_text);
    fprintf(stderr, "... now exiting to system ...\n");
    exit(1);
}
