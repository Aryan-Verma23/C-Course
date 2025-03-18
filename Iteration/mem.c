#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE  4 


void shuffle(int board[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }
}


void displayBoard(int board[][SIZE], int reveal[][SIZE]) {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (reveal[i][j]) {
                printf(" %2d ", board[i][j]);
            } else {
                printf(" ** ");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[SIZE][SIZE], revealed[SIZE][SIZE] = {0};
    int values[SIZE * SIZE];
    

    for (int i = 0; i < SIZE * SIZE; i++) {
        values[i] = (i / 2) + 1;
    }
    
    shuffle(values, SIZE * SIZE);
    
    
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = values[index++];
        }
    }
    
    int attempts = 0, pairs = 0;
    while (pairs < (SIZE * SIZE) / 2) {
        int x1, y1, x2, y2;
        displayBoard(board, revealed);
        
 
        printf("Enter coordinates of first card (row col): ");
        scanf("%d %d", &x1, &y1);
        x1--; y1--; 
        revealed[x1][y1] = 1;
        
        displayBoard(board, revealed);
        
        printf("Enter coordinates of second card (row col): ");
        scanf("%d %d", &x2, &y2);
        x2--; y2--;
        revealed[x2][y2] = 1;
        
        displayBoard(board, revealed);
        
        if (board[x1][y1] == board[x2][y2]) {
            printf("\nMatched!\n");
            pairs++;
        } else {
            printf("\nERRRRRR!\n");
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }
        
        attempts++;
    }
    
    printf("Congratulations! Game is completed in %d attempts.\n", attempts);
    return 0;
}
