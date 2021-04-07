#include "../headers/mergesort.h"

void MergeSort::merge( int numbers[], int l, int m, int r){
    int i, j, k, nl, nr; 

    nl = m-l+1; nr = r-m;
    int larr[nl], rarr[nr];

    for(i = 0; i<nl; i++)
        larr[i] = numbers[l+i];
    for(j = 0; j<nr; j++)
        rarr[j] = numbers[m+1+j];
    i = 0; j = 0; k = l;

    while(i < nl && j<nr) {
        if(larr[i] <= rarr[j]) {
            numbers[k] = larr[i];
            i++;
        }else{
            numbers[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl) {       
        numbers[k] = larr[i];
        i++; k++;
    }
    while(j<nr) { 
        numbers[k] = rarr[j];
        j++; k++;
    }
}

void MergeSort::sort( int numbers[], int l, int r){
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      MergeSort::sort(numbers, l, m);
      MergeSort::sort(numbers, m+1, r);
      MergeSort::merge(numbers, l, m, r);
   }
}

void MergeSort::swap( int *a,  int *b){
     int t = *a;
    *a = *b;
    *b = t;
}