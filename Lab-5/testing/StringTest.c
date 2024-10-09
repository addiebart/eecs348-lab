// This is a file I made to test string pointers and a int to month string function.

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
    int month = 2; //march
    char* monthStrPtr = getMonthStr(month);
    printf("%s", monthStrPtr);
    return 0;
}