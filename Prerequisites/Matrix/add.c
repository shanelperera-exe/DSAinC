#include <stdio.h>

#define M 4
#define N 4

void print_matrix(int matrix[M][N]);
void add(int A[M][N], int B[M][N], int C[M][N]);

int main(void) {
    int A[M][N] = {
        { 1, 1, 1 }, { 2, 2, 2 }, { 3, 3, 3 }, { 4, 4, 4 }
    };

    int B[M][N] = {
        { 2, 1, 1 }, { 1, 2, 2 }, { 2, 3, 3 }, { 3, 4, 4 }
    };

    printf("Matrix A: \n");
    print_matrix(A);

    printf("Matrix B: \n");
    print_matrix(B);

    int C[M][N];
    int i, j;
    add(A, B, C);

    printf("Result matrix: \n");
    print_matrix(C);

    return 0;
}

void print_matrix(int matrix[M][N]) {
    for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
		printf("\n"); 
	}
    printf("\n");
}

void add(int A[M][N], int B[M][N], int C[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
