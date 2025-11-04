#include <stdio.h>

#define N 1500  // Matrix size

int main() {
    static int A[N][N], B[N][N], C[N][N];  // static to avoid stack overflow
    int i, j, k;

    // Initialize matrices with some values (for testing)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    // Matrix multiplication
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print part of the result (to avoid huge output)
    printf("Result sample (top-left 5x5 block):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
