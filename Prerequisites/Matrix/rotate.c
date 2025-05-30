#include <stdio.h> 

#define R 4 // macros 
#define C 4 // macros 

void rotatematrix(int m, int n, int mat[R][C]);

int main() 
{ 
    // create a matrix of size RxC 
    // R - Rows, C - Columns 
    int mat[R][C] = { { 1, 2, 3, 4 }, 
                      { 5, 6, 7, 8 }, 
                      { 9, 10, 11, 12 }, 
                      { 13, 14, 15, 16 } }; 
  
    // Print input matrix 
    printf("\n Input Matrix \n"); 
    for (int i = 0; i < R; i++) { 
        for (int j = 0; j < C; j++) { 
            printf(" %d ", mat[i][j]); 
        } 
        printf("\n"); 
    } 
  
    // This function is rotate the elements of matrix. 
    rotatematrix(R, C, mat); 
  
    // Print rotated matrix 
    printf("\n Rotated Matrix \n"); 
    for (int i = 0; i < R; i++) { 
        for (int j = 0; j < C; j++) { 
            printf(" %d ", mat[i][j]); 
        } 
        printf("\n"); 
    } 
    printf("\n"); 
    return 0; 
}

void rotatematrix(int m, int n, int mat[R][C]) {
    int row = 0, col = 0; 
    int prev, curr; 
    /* 
    row: Starting row index 
    m: ending row index 
    col: starting column index 
    n: ending column index 
    i: iterator 
    */
    while (row < m && col < n) {
        if (row + 1 == m || col + 1 == n) 
            break; 
  
        // Store the first element of next row and this element will replace the first element of current row 
        prev = mat[row + 1][col];

        // Move elements of first row from remaining rows 
        for (int i = col; i < n; i++) { 
            curr = mat[row][i]; 
            mat[row][i] = prev; 
            prev = curr; 
        } 
        row++;

        // Move the elements of last column from the remaining columns 
        for (int i = row; i < m; i++) { 
            curr = mat[i][n - 1]; 
            mat[i][n - 1] = prev; 
            prev = curr; 
        } 
        n--;

        // Move the elements of last row from the remaining rows 
        if (row < m) { 
            for (int i = n - 1; i >= col; i--) { 
                curr = mat[m - 1][i]; 
                mat[m - 1][i] = prev; 
                prev = curr; 
            } 
        } 
        m--; 
  
        // Move the elements of first column from the remaining rows 
        if (col < n) { 
            for (int i = m - 1; i >= row; i--) { 
                curr = mat[i][col]; 
                mat[i][col] = prev; 
                prev = curr; 
            } 
        } 
        col++; 
    }
}