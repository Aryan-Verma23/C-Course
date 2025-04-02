#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 

void initializeBoard(char board[SIZE][SIZE], char temp[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
void shuffleBoard(char temp[SIZE][SIZE]);
void clearScreen();

int main() {
    srand(time(0));

    char board[SIZE][SIZE];
    char temp[SIZE][SIZE] = {
        {'@', '@', '#', '#'},
        {'$', '$', '%', '%'},
        {'&', '&', '~', '~'},
        {'?', '?', '=', '='}
    };

    initializeBoard(board, temp);
    shuffleBoard(temp);
    clearScreen();

    int x1, y1, x2, y2;
    int matches = 0;

    while (matches < SIZE * SIZE / 2) {
        displayBoard(board);
        printf("Enter coordinates (x1 y1) to flip a card: ");
        scanf("%d %d", &x1, &y1);

        if (board[x1][y1] != '*') {
            printf("Card already revealed, try again!\n");
            continue;
        }
        board[x1][y1] = temp[x1][y1];
        displayBoard(board);
        printf("Enter coordinates (x2 y2) to flip the second card: ");
        scanf("%d %d", &x2, &y2);

        if (board[x2][y2] != '*') {
            printf("Card already revealed, try again!\n");
            board[x1][y1] = '*'; 
            continue;
        }
        board[x2][y2] = temp[x2][y2];
        displayBoard(board);

        if (board[x1][y1] == board[x2][y2]) {
            printf("It's a match!\n");
            matches++;
        } else {
            printf("Not a match!\n");
    
            board[x1][y1] = '*';
            board[x2][y2] = '*';
        }

        clearScreen();
    }

    printf("Congratulations! You found all matches!\n");
    return 0;
}

void initializeBoard(char board[SIZE][SIZE], char temp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '*'; 
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    printf("\nCo ordinates starts with (0,0)  to (3,3)\n");
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void shuffleBoard(char temp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r = rand() % SIZE;
            int c = rand() % SIZE;
            char tempCard = temp[i][j];
            temp[i][j] = temp[r][c];
            temp[r][c] = tempCard;
        }
    }
}

void clearScreen() {
    printf("\033[H\033[J");  
}