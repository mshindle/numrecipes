//
// Created by mshindle on 11/1/26.
//

#include <stddef.h>
#include <numrecipes/matrix.h>

void *pt_matrix_multiply(void *arg) {
    const matrix_worker_t *worker = (const matrix_worker_t *) arg;
    const int row = worker->row;
    const int column = worker->column;

    (*worker->mc)[row][column] = 0;
    for (int position = 0; position < worker->size; position++) {
        (*worker->mc)[row][column] +=
            (*worker->ma)[row][position] * (*worker->mb)[position][column];
    }
    return NULL;
}
