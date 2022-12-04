#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH 4

void printBoard(int [LENGTH][LENGTH]);
void fillBoard(int [LENGTH][LENGTH]);
void newNumber(int [LENGTH][LENGTH], int [LENGTH*LENGTH][2], int);
int checkValid(int [LENGTH][LENGTH], int [LENGTH*LENGTH][2]);
int getTotal(int [LENGTH][LENGTH]);
void logic(int [LENGTH][LENGTH]);
void upArrow(int [LENGTH][LENGTH]);

int main () {
    int board[4][4];
    int validBoard[LENGTH*LENGTH][2];
    int total = 0;
    int index = -1;

    srand(time(NULL));
    fillBoard(board);
    index = checkValid(board, validBoard);
    newNumber(board, validBoard, index);
    index = checkValid(board, validBoard);
    newNumber(board, validBoard, index);
    index = checkValid(board, validBoard);
    printBoard(board);
    while (1) {
        logic(board);
        newNumber(board, validBoard, index);
        printBoard(board);
        total = getTotal(board);
        index = checkValid(board, validBoard);
        // fix the win con bc you might be able to move still
        if (index == -1) {
            printf("Oh no you lost! You finished with a score of %d\n", total);
            break;
        }
    }
    return 0;
}

void printBoard(int board[LENGTH][LENGTH]) {
    printf(" ");
    for (int i = 0; i < LENGTH*2+1; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < LENGTH; i++) {
        printf("| ");
        for (int j = 0; j < LENGTH; j++) {
            printf("%d ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" ");
    for (int i = 0; i < LENGTH*2+1; i++) {
        printf("-");
    }
    printf("\n\n");
}

void fillBoard(int board[LENGTH][LENGTH]) {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            board[i][j] = 0;
        }
    }
}

void newNumber(int board[LENGTH][LENGTH], int validBoard[LENGTH*LENGTH][2], int index) {
    int x = rand() % (index+1);
    int y;
    if (rand() % 10 == 1) {
        y = 4;
    } else {
        y = 2;
    }
    board[validBoard[x][0]][validBoard[x][1]] = y;
}

int checkValid(int board[LENGTH][LENGTH], int validBoard[LENGTH*LENGTH][2]) {
    int valid = -1;
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (board[i][j] == 0) {
                valid++;
                validBoard[valid][0] = i;
                validBoard[valid][1] = j;
            }
        }
    }
    return valid;
}

int getTotal(int board[LENGTH][LENGTH]) {
    int total = 0;
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            total += board[i][j];
        }
    }
    return total;
}

void logic(int board[LENGTH][LENGTH]) {
    int input = 0;
    while (!input) {
        if (getchar() == '\033') {
            getchar();
            switch(getchar()) {
                case 'A':
                    // code for arrow up
                    upArrow(board);
                    input = 1;
                    break;
                case 'B':
                    // code for arrow down
                    input = 1;
                    break;
                case 'C':
                    // code for arrow right
                    input = 1;
                    break;
                case 'D':
                    // code for arrow left
                    input = 1;
                    break;
            }
        }
    }
}

void upArrow(int board[LENGTH][LENGTH]) {
    for (int j = 0; j < LENGTH; j++) {
        for (int i = 0; i < LENGTH-1; i++) {
            if (board[i][j] == board[i+1][j]) {
                
            }
        }
    }
}