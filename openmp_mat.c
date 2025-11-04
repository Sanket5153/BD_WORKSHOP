#include <stdio.h>
#include <omp.h>

#define N 1500  // Matrix size

int main() {
    static int A[N][N], B[N][N], C[N][N];  // static to avoid stack overflow
    int i, j, k;

    // Initialize matrices
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0;
        }
    }

    double start = omp_get_wtime(); // start timer

    // Parallel matrix multiplication
    #pragma omp parallel for private(i,j,k) shared(A,B,C)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            int sum = 0;
            for (k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    double end = omp_get_wtime(); // end timer

    // Print part of result
    printf("Result sample (top-left 5x5 block):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("\nTime taken with OpenMP: %f seconds\n", end - start);

    return 0;
}
