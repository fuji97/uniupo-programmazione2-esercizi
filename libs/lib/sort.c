#include "sort.h"

int partition(int arr[], int low, int high) {
    int pivot, i;
    // Pivot: l'elemento da piazzare alla posizione corretta
    pivot = arr[high];
    
    i = low - 1; // Indice del valore più piccolo
    int j;
    
    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    int pi;
    if (low < high) {
        pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}