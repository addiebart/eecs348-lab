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
   int outcome[5];
   for (char i = 0; i < 5; i++) {
        outcome[i] = 0;
   }

   //find how many 7 blocks fit, and then how many 6 blocks fit in the remaining space, and so on, until 2 blocks.
   //backtrack to exaust all solutions
}