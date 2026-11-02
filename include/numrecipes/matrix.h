//
// Created by mshindle on 11/1/26.
//

#ifndef NUMRECIPES_MATRIX_H
#define NUMRECIPES_MATRIX_H

/* constants */

#define ARRAY_SIZE 10

/* types */

typedef int matrix_t[ARRAY_SIZE][ARRAY_SIZE];
typedef struct {
    int id;
    int size;
    int row;
    int column;
    matrix_t *ma;
    matrix_t *mb;
    matrix_t *mc;
} matrix_worker_t;

/* functions */

void *pt_matrix_multiply(void *arg);

#endif //NUMRECIPES_MATRIX_H
