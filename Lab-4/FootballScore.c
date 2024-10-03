#include <stdio.h>

int main() {
    //prompt and take input
    printf("Enter 0 or 1 to STOP");
    printf("Enter the NFL score:");
    int score;
    scanf(" %d", &score);

    /*
    blocks: 2, 3, 6, 7, 8
    */

   // this calls for a recursive solution
   int outcome[5] = {0};
   int types[5] = {8,7,6,3,2};

   //find how many 8 blocks fit, and then how many 7 blocks fit in the remaining space, and so on, until 2 blocks.
   //backtrack to exaust all solutions

   for (int typeIndex = 0; typeIndex < 5; typeIndex++) {
        int type = types[typeIndex]; // stores the block size of the iteration, ex 7 for TD+PAT
        int numBlocksFit = score / type; // find how many of that block size we can fit in the score
        int remainingSpace = score % type;
        if (remainingSpace == 0) {
            int outArr[5] = {0};
            outArr[typeIndex] = numBlocksFit;
            printout(outArr);
            continue;
        } else if (remainingSpace == 1) {
            // no solutions, continue
        } else {
            // find solutions
        }
   }
}

void printout (int* outcome) {
    printf("%d TD+2pt, %d TD+FG, %d TD, %d FG, %d Safety", outcome[0], outcome[1], outcome[2], outcome[3], outcome[4]);
}