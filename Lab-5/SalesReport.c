#include <stdio.h>

char* getMonthStr(int month) { // returns a str with month name depending on passed int, ex: 1 -> february.
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
    printf("Provide 12 Figures:\n"); // prompt for figures
    float figures[12];
    float hold;
    for (int i = 0; i < 12; i++) { // loop to read figures
        scanf(" %f", &hold);
        figures[i] = hold;
    }

    printf("\nMonthly Sales Report for 2024:\n\n");
    printf("Month\tSales\n");
    for (int i = 0; i < 12; i++) {
        char* monthStr = getMonthStr(i); // get month str for index
        printf("%s:\t$%.2f\n", monthStr, figures[i]); // print figure for index along month str
    }

    printf("\nSales Summary Report:\n\n");
    float min, max, average; // declare some vars
    int maxi, mini = 0;
    for (int i = 0; i < 12; i++) { // for all of the figures
        if (i == 0) { //assume the first figures is the min and max
            min = figures[i];
            max = figures[i];
        } else {
            if (figures[i] < min) { // if a lower figure than min is found, make it min and take note of its index
                min = figures[i];
                mini = i;
            }
            if (figures[i] > max) { // if a greater figure than max is found, max it max and take note of its index
                max = figures[i];
                maxi = i;
            }
        }
        average += figures[i]; // add figure to average
    }
    average /= 12.0F; // divide average by 12 to get real average
    printf("%s\t$%.2f\t(%s)\n", "Minimum Sales:", min, getMonthStr(mini)); // printing
    printf("%s\t$%.2f\t(%s)\n", "Maximum Sales:", max, getMonthStr(maxi));
    printf("%s\t$%.2f\n", "Average Sales:", average);

    printf("\nSix-Month moving average report:\n\n");
    for (int i = 0; i < 12; i += 2) { // cycle every 2 months
        int monthIndex1 = i;
        int monthIndex2 = i + 1;
        printf("%s-%s\t$%.2f\n", getMonthStr(monthIndex1), getMonthStr(monthIndex2), (figures[monthIndex1] + figures[monthIndex2]) / 2.0F); //print average of them
    }

    printf("\nSales report (hightest to lowest):\n\n");
    printf("Month\tSales\n");
    float sortedFigures[12];
    int monthNumbers[12];
    for (int i = 0; i < 12; i++) {
        sortedFigures[i] = figures[i]; //append copy
        monthNumbers[i] = i;
        //bubble sort, N is constant 12 so bad O notation is a nonissue
        while (i != 0 && sortedFigures[i] < sortedFigures[i - 1]) { // employ short circuit logic eval
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
