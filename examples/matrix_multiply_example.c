//
// Created by mshindle on 11/1/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <numrecipes/matrix.h>

static void print_matrix(const char *name, matrix_t m, int size) {
    printf("MATRIX: The matrix %s is :\n", name);
    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++) {
            printf("%5d ", m[row][column]);
        }
        printf("\n");
    }
}

int main() {
    int size = ARRAY_SIZE;
    int row, column;
    matrix_worker_t *worker;
    pthread_t peer[ARRAY_SIZE * ARRAY_SIZE];
    matrix_worker_t *workers[ARRAY_SIZE * ARRAY_SIZE];
    matrix_t MA, MB, MC;

    /* create matrix data */
    for (row = 0; row < size; row++) {
        for (column = 0; column < size; column++) {
            MA[row][column] = row + column;
            MB[row][column] = (row == column) ? 2 : 1;
            MC[row][column] = 0;
        }
    }

    /* process matrix by row & col */
    for (row = 0; row < size; row++) {
        for (column = 0; column < size; column++) {
            int id = column + row * size;
            worker = (matrix_worker_t *) malloc(sizeof(matrix_worker_t));
            if (worker == NULL) {
                perror("malloc");
                return 1;
            }
            workers[id] = worker;
            worker->id = id;
            worker->size = size;
            worker->row = row;
            worker->column = column;
            worker->ma = &MA;
            worker->mb = &MB;
            worker->mc = &MC;
            if (pthread_create(&(peer[id]), NULL, pt_matrix_multiply, worker) != 0) {
                fprintf(stderr, "pthread_create failed\n");
                return 1;
            }
        }
    }

    /* wait for peers to finish */
    for (int i = 0; i < (size * size); i++) {
        pthread_join(peer[i], NULL);
        free(workers[i]);
    }

    /* print matrices */
    print_matrix("A", MA, size);
    print_matrix("B", MB, size);
    print_matrix("C (result)", MC, size);
    return 0;
}
