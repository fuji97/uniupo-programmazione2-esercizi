#include "utils.h"

void swap(int arr[], int val1, int val2) {
    int sw = arr[val1];
    arr[val1] = arr[val2];
    arr[val2] = sw;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}