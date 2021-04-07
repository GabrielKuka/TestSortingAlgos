#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include "./headers/utils.h"
#include "./headers/quicksort.h"
#include "./headers/heapsort.h"
#include "./headers/mergesort.h"
#include "./headers/timsort.h"

using namespace std;
using namespace std::chrono;

typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;


string printExecutionTime(ClockTime, ClockTime);
void testQuickSort();
void testMergeSort();
void testHeapSort();
void testTimSort();

int main(){

    testQuickSort();
    testMergeSort();
    testHeapSort();
    testTimSort();

    return 0;
}

void testQuickSort(){
    Utils utils;
    utils.readFiles();
    vector<int*> lists = utils.getNumbers();

    cout << "~~~~~\nTesting Quick Sort..." << endl;
    for(int i = 0; i < 5; i++){
        int size = Utils::getSize(i); 
        ClockTime start = Clock::now();
        QuickSort::sort(lists[i], 0, size-1);
        ClockTime end = Clock::now();
        cout << "Size: " <<  size << " - " << printExecutionTime(start, end) << "\n";
    }
    utils.clearSpace();
    vector<int*>().swap(lists);
}

void testMergeSort(){
    Utils utils;
    utils.readFiles();
    vector<int*> lists = utils.getNumbers();

    cout << "~~~~~\nTesting Merge Sort..." << endl;
    for(int i = 0; i < 5; i++){
        int size = Utils::getSize(i); 
        ClockTime start = Clock::now();
        MergeSort::sort(lists[i], 0, size-1);
        ClockTime end = Clock::now();
        cout << "Size: " <<  size << " - " << printExecutionTime(start, end) << "\n";
    }
    utils.clearSpace();
}

void testHeapSort(){
    Utils utils;
    utils.readFiles();
    vector<int*> lists = utils.getNumbers();

    cout << "~~~~~\nTesting Heap Sort..." << endl;
    for(int i = 0; i < 5; i++){
        int size = Utils::getSize(i); 
        ClockTime start = Clock::now();
        HeapSort::sort(lists[i], size);
        ClockTime end = Clock::now();
        cout << "Size: " <<  size << " - " << printExecutionTime(start, end) << "\n";
    }
    utils.clearSpace();
}

void testTimSort(){
    Utils utils;
    utils.readFiles();
    vector<int*> lists = utils.getNumbers();

    cout << "~~~~~\nTesting Tim Sort..." << endl;
    for(int i = 0; i < 5; i++){
        int size = Utils::getSize(i); 
        ClockTime start = Clock::now();
        TimSort::sort(lists[i], size);
        ClockTime end = Clock::now();
        cout << "Size: " <<  size << " - " << printExecutionTime(start, end) << "\n";
    }
    utils.clearSpace();
}

string printExecutionTime(ClockTime start_time, ClockTime end_time){
    auto execution_time_ns = duration_cast<nanoseconds>(end_time - start_time).count();
    auto execution_time_ms = duration_cast<microseconds>(end_time - start_time).count();
    auto execution_time_sec = duration_cast<seconds>(end_time - start_time).count();
    auto execution_time_min = duration_cast<minutes>(end_time - start_time).count();
    auto execution_time_hour = duration_cast<hours>(end_time - start_time).count();

    string result = "Time: ";
    if(execution_time_hour > 0)
        result += to_string(execution_time_hour) + " Hours, "; 
    if(execution_time_min > 0)
        result += to_string(execution_time_min % 60) + " Minutes, ";
    if(execution_time_sec > 0)
        result += to_string(execution_time_sec % 60) + "s, "; 
    if(execution_time_ms > 0)
        result += to_string(execution_time_ms % long(1E+3)) + "ms, "; 
    if(execution_time_ns > 0)
        result += to_string(execution_time_ns % long(1E+6)) + "ns.\n"; 
    return result;
}
