// Could not get functions to return arrays nor deference passed pointers, Lab TA said it was okay to call printMatrix() from within the other functions.

#include <stdio.h>

#define SIZE 5

void printMatrix(int m1[SIZE][SIZE]) { // formats and prints a passed matrix
    for (int row = 0; row < SIZE; row++) { // rows
        printf("[ ");
        for (int col = 0; col < SIZE; col++) { // cols
            printf("%d ", m1[row][col]); // print element with whitespace
        }
        printf("]\n");
    }
}

void addMatricies(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) { // prints the sum of two passed matricies
    int out[SIZE][SIZE] = {0}; // init an out matrix
    for (int row =  0; row < SIZE; row++) { // cycle rows
        for (int col = 0; col < SIZE; col++) { // cycles cols
            out[row][col] = m1[row][col] + m2[row][col]; //add the positions of the input matricies to that of out
        }
    }
    printf("\nMatrix 1 + Matrix 2:\n"); // printing
    printMatrix(out);
}

void multiplyMatricies(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) { // prints the product of two passed matricies, order matters
    int out[SIZE][SIZE] = {0}; // init an out matrix
    for (int row = 0; row < SIZE; row++) { //for each row
        for (int col = 0; col < SIZE; col++) { //for each column
            int resultForTile = 0;
            for (int item = 0; item < SIZE; item++) { // add products into tile in out
                resultForTile += m1[row][item] * m2[item][col]; // add this product to the tile result
            }
            out[row][col] = resultForTile; // set the out tile to the tile result
        }
    }
    printf("\nMatrix 1 * Matrix 2:\n"); //printing
    printMatrix(out);
}

void transposeMatrix(int m1[SIZE][SIZE]) { //prints the transpose of a provided matrix
    int out[SIZE][SIZE] = {0}; // init an out matrix
    for (int row = 0; row < SIZE; row++) { // cycle rows
        for (int col =  0; col < SIZE; col++) { // cycle cols
            out[row][col] = m1[col][row]; // swap the rows and cols, add to out
        }
    }
    printf("\nTranspose of Matrix 1:\n"); // printing
    printMatrix(out);
}

int main() { // driver

    int m1[SIZE][SIZE] = { //define matrix 1
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = { //define matrix 2
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    printf("Matrix 1:\n"); //calls and printing
    printMatrix(m1);
    printf("\nMatrix 2:\n");
    printMatrix(m2);
    addMatricies(m1, m2);
    multiplyMatricies(m1, m2);
    transposeMatrix(m1);
}