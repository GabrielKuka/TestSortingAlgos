#include "../headers/timsort.h"
#include "../headers/mergesort.h"

void TimSort::sort(int numbers[], int n){

    for (int i = 0; i < n; i+=TimSort::RUN)
        TimSort::insertionSort(numbers, i, TimSort::min((i+TimSort::RUN-1),
                                    (n-1)));
 
    for (int size = TimSort::RUN; size < n;
                             size = 2*size)
    {
         
        for (int left = 0; left < n;
                             left += 2*size)
        {
             
            int mid = left + size - 1;
            int right = TimSort::min((left + 2*size - 1),
                                            (n-1));
 
              if(mid < right)
                MergeSort::merge(numbers, left, mid, right);
        }
    }
}

void TimSort::insertionSort(int numbers[], int l, int r){
    for (int i = l + 1; i <= r; i++){
            int temp = numbers[i];
            int j = i - 1;
            while (j >= l && numbers[j] > temp)
            {
                numbers[j+1] = numbers[j];
                j--;
            }
            numbers[j+1] = temp;
        }
}


int TimSort::min(int a, int b){
    return a<b?a:b;
}