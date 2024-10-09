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
    printf("Provide 12 Figures:\n");
    float figures[12];
    float hold;
    for (int i = 0; i < 12; i++) {
        scanf(" %f", &hold);
        figures[i] = hold;
    }

    printf("\nMonthly Sales Report for 2024:\n\n");
    printf("Month\tSales\n");
    for (int i = 0; i < 12; i++) {
        char* monthStr = getMonthStr(i);
        printf("%s:\t$%.2f\n", monthStr, figures[i]);
    }

    printf("\nSales Summary Report:\n\n");
    float min, max, average;
    int maxi, mini = 0;
    for (int i = 0; i < 12; i++) {
        if (i == 0) {
            min = figures[i];
            max = figures[i];
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
    average /= 12.0F;
    printf("%s\t$%.2f\t(%s)\n", "Minimum Sales:", min, getMonthStr(mini));
    printf("%s\t$%.2f\t(%s)\n", "Maximum Sales:", max, getMonthStr(maxi));
    printf("%s\t$%.2f\n", "Average Sales:", average);

    printf("\nSix-Month moving average report:\n\n");
    for (int i = 0; i < 12; i += 2) {
        int monthIndex1 = i;
        int monthIndex2 = i + 1;
        printf("%s-%s\t$%.2f\n", getMonthStr(monthIndex1), getMonthStr(monthIndex2), (figures[monthIndex1] + figures[monthIndex2]) / 2.0F);
    }

    printf("\nSales report (hightest to lowest):\n\n");
    printf("Month\tSales\n");
    float sortedFigures[12];
    int monthNumbers[12];
    for (int i = 0; i < 12; i++) {
        sortedFigures[i] = figures[i]; //append copy
        monthNumbers[i] = i;
        //bubble sort
        int index = i;
        while (index != 0 && sortedFigures[i] < sortedFigures[i - 1]) {
            float tempFigure = sortedFigures[i - 1]; //set tempFigure
            int tempMonth = monthNumbers[i - 1];
            sortedFigures[i - 1] = sortedFigures[i]; //make swap
            monthNumbers[i - 1] = monthNumbers[i];
            sortedFigures[i] = tempFigure;
            monthNumbers[i] = tempMonth;
        }
        //sortedFigures is now sorted.
    }
    //all elements are added to and sorted in sortedFigures, as are months
    for (int i = 0; i < 12; i++) printf("%s\t$%.2f\n", getMonthStr(monthNumbers[i]), sortedFigures[i]); //print

    return 0;
}
