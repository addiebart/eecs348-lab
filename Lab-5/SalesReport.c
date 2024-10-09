#include <stdio.h>

int main() {
    float figures[12];
    float hold;
    for (int i = 0; i < 12; i++) {
        scanf(" %f", &hold);
        figures[i] = hold;
    }

    printf("Monthly Sales Report for 2024:\n\n");
    printf("Month\tSales\n");
    for (int i = 0; i < 12; i++) {
        switch (i) {
            case 0:
                printf("%s:\t$%,2f\n", "January", figures[i]);
                break;
            case 1:
                printf("%s:\t$%,2f\n", "February", figures[i]);
                break;
            case 2:
                printf("%s:\t$%,2f\n", "March", figures[i]);
                break;
            case 3:
                printf("%s:\t$%,2f\n", "April", figures[i]);
                break;
            case 4:
                printf("%s:\t$%,2f\n", "May", figures[i]);
                break;
            case 5:
                printf("%s:\t$%,2f\n", "June", figures[i]);
                break;
            case 6:
                printf("%s:\t$%,2f\n", "July", figures[i]);
                break;
            case 7:
                printf("%s:\t$%,2f\n", "August", figures[i]);
                break;
            case 8:
                printf("%s:\t$%,2f\n", "September", figures[i]);
                break;
            case 9:
                printf("%s:\t$%,2f\n", "October", figures[i]);
                break;
            case 10:
                printf("%s:\t$%,2f\n", "November", figures[i]);
                break;
            case 11:
                printf("%s:\t$%,2f\n", "December", figures[i]);
                break;
        }
    }

    printf("\nSales Summary Report:\n\n");
    float min, max, average;
    int maxi, mini = 0;
    for (int i = 0; i < 12; i++) {
        if (i == 0) {
            min, max = figures[i];
        } else {
            if (figures[i] < min) {
                min = figures[i];
                mini = i;
            }
            if (figures[i] > max) {
                max = figures[i];
                maxi = i;
            }
        }
        average += figures[i]; 
    }
    average /= 12;
    printf("%s\t$%.2f\n", "Minimum Sales:", min);
    printf("%s\t$%.2f\n", "Maximum Sales:", max);
    printf("%s\t$%.2f\n\n", "Average Sales:", average);

    return 0;
}
