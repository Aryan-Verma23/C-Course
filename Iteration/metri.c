#include <stdio.h>
#define length 10
void inputMatrix(int mat[length][length], int row, int col) {
    printf("Enter elements:\n");
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            scanf("%d", &mat[i][j]);
}

void MatrixShow(int mat[length][length], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void addMatrices(int a[length][length], int b[length][length], int row, int col) {
    int result[length][length];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result[i][j] = a[i][j] + b[i][j];
    
    printf("Addition Result:\n");
    MatrixShow(result, row, col);
}

void subtractMatrices(int a[length][length], int b[length][length], int row, int col) {
    int result[length][length];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result[i][j] = a[i][j] - b[i][j];
    
    printf("Subtraction Result:\n");
    MatrixShow(result, row, col);
}

void MatrixProduct (int a[length][length], int b[length][length], int r1, int c1, int c2) {
    int result[length][length] = {0};
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c2; j++)
            for(int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
    
    printf("Product Result:\n");
    MatrixShow(result, r1, c2);
}

void transposeMatrix(int mat[length][length], int row, int col) {
    int trans[length][length];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            trans[j][i] = mat[i][j];
    
    printf("Transpose:\n");
    MatrixShow(trans, col, row);
}

void upperLowerTriangular(int mat[length][length], int n) {
    int upper[length][length] = {0}, lower[length][length] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i <= j)
                upper[i][j] = mat[i][j];
            if(i >= j)
                lower[i][j] = mat[i][j];
        }
    }

    printf("Upper Triangular Matrix:\n");
    MatrixShow(upper, n, n);

    printf("Lower Triangular Matrix:\n");
    MatrixShow(lower, n, n);
}

int main() {
    int choice;
    int a[length][length], b[length][length];
    int r1, c1, r2, c2;

    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Addition of two matrices\n");
        printf("2. Subtraction of two matrices\n");
        printf("3. Product of two matrices\n");
        printf("4. Transpose of a matrix\n");
        printf("5. Upper and Lower triangular matrix\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter rows and columns of matrices: ");
                scanf("%d%d", &r1, &c1);
                printf("Matrix A:\n");
                inputMatrix(a, r1, c1);
                printf("Matrix B:\n");
                inputMatrix(b, r1, c1);
                addMatrices(a, b, r1, c1);
                break;

            case 2:
                printf("Enter rows and columns of matrices: ");
                scanf("%d%d", &r1, &c1);
                printf("Matrix A:\n");
                inputMatrix(a, r1, c1);
                printf("Matrix B:\n");
                inputMatrix(b, r1, c1);
                subtractMatrices(a, b, r1, c1);
                break;

            case 3:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d%d", &r1, &c1);
                printf("Enter columns of Matrix B (rows of B must be %d): ", c1);
                scanf("%d", &c2);
                printf("Matrix A:\n");
                inputMatrix(a, r1, c1);
                printf("Matrix B:\n");
                inputMatrix(b, c1, c2);
                MatrixProduct (a, b, r1, c1, c2);
                break;

            case 4:
                printf("Enter rows and columns of the matrix: ");
                scanf("%d%d", &r1, &c1);
                inputMatrix(a, r1, c1);
                transposeMatrix(a, r1, c1);
                break;

            case 5:
                printf("Enter order of the square matrix: ");
                scanf("%d", &r1);
                inputMatrix(a, r1, r1);
                upperLowerTriangular(a, r1);
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 6);

    return 0;
}