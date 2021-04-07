class TimSort{
    public:
        static void sort(int numbers[], int n);
        static void merge(int numbers[], int l, int m, int r);
        static void insertionSort(int numbers[], int l, int r);
        static int min(int a, int b);
        static const int RUN = 128;
};