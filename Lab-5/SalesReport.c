#include <stdio.h>

char* getMonthStr(int month) {
    char* strings[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    return strings[month];
}

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
        char* monthStr = getMonthStr(i);
        printf("%s:\t$%,2f\n", monthStr, figures[i]);
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
    printf("%s\t$%.2f\t(%s)\n", "Minimum Sales:", min, getMonthStr(mini));
    printf("%s\t$%.2f\t(%s)\n", "Maximum Sales:", max, getMonthStr(maxi));
    printf("%s\t$%.2f\n\n", "Average Sales:", average);

    return 0;
}
