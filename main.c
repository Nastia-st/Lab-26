#include <stdio.h>
#define N 3
#define M 4

void printMatrix(int A[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    system("chcp 65001");
    int A[N][M] = {
        {3, 5, 7, 1},
        {2, 9, 4, 6},
        {8, 0, 3, 2}
    };

    printf("Початкова матриця:\n");
    printMatrix(A);
    int max = A[0][0];
    int max_i = 0, max_j = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] > max) {
                max = A[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    if (max_i != 0) {
        for (int j = 0; j < M; j++) {
            int temp = A[0][j];
            A[0][j] = A[max_i][j];
            A[max_i][j] = temp;
        }
    }
    if (max_j != 0) {
        for (int i = 0; i < N; i++) {
            int temp = A[i][0];
            A[i][0] = A[i][max_j];
            A[i][max_j] = temp;
        }
    }

    printf("Матриця після перестановки:\n");
    printMatrix(A);
    return 0;
}