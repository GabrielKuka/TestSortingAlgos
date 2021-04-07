#include <vector>
#include <fstream>

using namespace std;

class Utils{
    public:
        Utils();
        void readFiles();
        void accessFiles();
        static void printArray(  int numbers[], int n);
        static void generateRandomNumbers(  int numbers[], int n);
        void clearSpace();
        vector<int*> getNumbers();
        static int getSize(int&);
    private:
        int *data100 = new int[100];
        int *data1000 = new int[1000];
        int *data10000 = new int[10000];
        int *data100000 = new int[100000];
        int *data1000000 = new int[1000000];
        vector<int*> data;
        ifstream files[5];
};