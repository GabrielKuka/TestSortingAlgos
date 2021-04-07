#include <iostream>
#include <algorithm>
#include <string>
#include "./headers/utils.h"
#include <vector>

using namespace std;

Utils::Utils(){
    this->data.push_back(data100);
    this->data.push_back(data1000);
    this->data.push_back(data10000);
    this->data.push_back(data100000);
    this->data.push_back(data1000000);
    
}

void Utils::accessFiles(){
    files[0] = ifstream("files/100numbers.txt");
    files[1] = ifstream("files/1000numbers.txt");
    files[2] = ifstream("files/10000numbers.txt");
    files[3] = ifstream("files/100000numbers.txt");
    files[4] = ifstream("files/1000000numbers.txt");
}

void Utils::readFiles(){
    accessFiles();
    string line;
    // Store the data into arrays
    for(int i =0; i < 5; i++){
        int j = 0;
        if(this->files[i].is_open()){
            while(getline(files[i], line)){
                data[i][j] = stoi(line);
                j++;
            }
            files[i].close();
        }
    }
}

vector<int*> Utils::getNumbers(){
    return this->data;
}

int Utils::getSize(int &i){
    switch(i){
        case 0:
            return 100;
        case 1:
            return 1000;
        case 2:
            return 10000;
        case 3:
            return 100000;
        case 4: 
            return 1000000;
        default:
            return 0;
    }
}

void Utils::clearSpace(){
    delete [] data100;
    delete [] data1000;
    delete [] data10000;
    delete [] data100000;
    delete [] data1000000;
    /*
    switch(i){
        case 0:
            delete [] data100;
        case 1:
            delete [] data1000;
        case 2:
            delete [] data10000;
        case 3:
            delete [] data100000;
        case 4:
            delete [] data1000000;
        default:
            return;
    }
    */
}

void Utils::printArray(  int numbers[], int n){
    for(int i=0; i<n; i++)
        cout << numbers[i] << " ";
    cout << endl;
}

void Utils::generateRandomNumbers(  int numbers[], int n){
    for(int i=0;i<n;i++)
        numbers[i]=rand()%100; 
}