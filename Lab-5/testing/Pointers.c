#include <stdio.h>

int* returnArrayPtr() {
    int arr[2][2] = {{1,2},{3,4}};
    int* arrPtr = &arr;
    return arrPtr;
}

int main() {
    printf("%d", (long)returnArrayPtr());
}