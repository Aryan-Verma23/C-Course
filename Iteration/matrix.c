#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void transposeMatrix(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            B[j][i] = A[i][j];
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void upperLowerTriangular(int A[MAX][MAX], int rows, int cols) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j < i)
                printf("0 ");
            else
                printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Lower Triangular Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j > i)
                printf("0 ");
            else
                printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int rows, cols, choice;
    while (1) {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Addition\n2. Subtraction\n3. Transpose\n4. Multiply\n5. Upper & Lower Triangular Matrices\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6)
            break;
        printf("Enter number of rows and columns: ");
        scanf("%d %d", &rows, &cols);

        if (choice == 1 || choice == 2) {
            printf("Enter first matrix:\n");
            inputMatrix(A, rows, cols);
            printf("Enter second matrix:\n");
            inputMatrix(B, rows, cols);
            if (choice == 1) {
                addMatrices(A, B, C, rows, cols);
                printf("Result of Addition:\n");
            } else {
                subtractMatrices(A, B, C, rows, cols);
                printf("Result of Subtraction:\n");
            }
            printMatrix(C, rows, cols);
        } else if (choice == 3) {
            inputMatrix(A, rows, cols);
            transposeMatrix(A, B, rows, cols);
            printf("Transpose of the Matrix:\n");
            printMatrix(B, cols, rows);
        } 
        
        
        else if (choice == 4) {
            int c2;
            printf("Enter columns for second matrix: ");
            scanf("%d", &c2);
            inputMatrix(A, rows, cols);
            inputMatrix(B, cols, c2);
            multiplyMatrices(A, B, C, rows, cols, c2);
            printf("Result of Multiplication:\n");
            printMatrix(C, rows, c2);
        } else if (choice == 5) {
            inputMatrix(A, rows, cols);
            upperLowerTriangular(A, rows, cols);
        }
    }
    return 0;}
