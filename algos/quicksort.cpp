#include "../headers/quicksort.h"

int QuickSort::partition( int numbers[], int low, int high){

    // Pick right-most element as the pivot
    int pivot = numbers[high];

    int i = (low - 1);

    // Traverse array and compare elements with the pivot
    for(int j=low; j<high; j++){
        if(numbers[j] <= pivot){
            i++;
            QuickSort::swap(&numbers[i], &numbers[j]);
        }
    }

    // Swap pivot in the right position 
    QuickSort::swap(&numbers[i+1], &numbers[high]);

    // Return the new position of the pivot
    return (i+1);

}

void QuickSort::sort( int numbers[], int low, int high){
    if(low < high){
        int p = QuickSort::partition(numbers, low, high);

        QuickSort::sort(numbers, low, p-1);
        QuickSort::sort(numbers, p+1,high);
    }
}

void QuickSort::swap( int *a,  int *b){
     int t = *a;
    *a = *b;
    *b = t;
}