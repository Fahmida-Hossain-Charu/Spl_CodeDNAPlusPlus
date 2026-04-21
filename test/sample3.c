#include <stdio.h>

void print_matrix(int rows, int cols, int mat[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

void transpose(int rows, int cols, int mat[rows][cols], int result[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int transposed[3][2];
    
    printf("Original matrix:\n");
    print_matrix(2, 3, matrix);
    
    transpose(2, 3, matrix, transposed);
    
    printf("\nTransposed matrix:\n");
    print_matrix(3, 2, transposed);
    
    return 0;
}