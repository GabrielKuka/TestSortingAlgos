#include "../headers/heapsort.h"
#include <iostream>

void HeapSort::heapify(int numbers[], int n, int i){

    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    if (l < n && numbers[l] > numbers[largest])
        largest = l;
  
    // If right child is larger than largest so far
    if (r < n && numbers[r] > numbers[largest])
        largest = r;
  
    // If largest is not root
    if (largest != i) {
        HeapSort::swap(&numbers[i], &numbers[largest]);
  
        // Recursively heapify the affected sub-tree
        HeapSort::heapify(numbers, n, largest);
    }
}

void HeapSort::sort(int numbers[], int n){
// Build heap (renumbersange numbersay)
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapSort::heapify(numbers, n, i);
  
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        HeapSort::swap(&numbers[0], &numbers[i]);
  
        // call max heapify on the reduced heap
        HeapSort::heapify(numbers, i, 0);
    }
}

void HeapSort::swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}