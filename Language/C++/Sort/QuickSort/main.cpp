#include <iostream>

using namespace std;

void print_array(int a[], int n);
void quick_sort(int a[], int low, int high);
void sort(int a[], int n);


void print_array(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int partition(int a[], int low, int high) {
    int pivotKey = a[low];
    while(low < high) {
        while(low < high && a[high] > pivotKey)
            --high;
        a[low] = a[high];
        while(low < high && a[low] <= pivotKey)
            ++low;
        a[high] = a[low];
    }
    a[low] = pivotKey;

    return low;
}

void quick_sort(int a[], int low, int high) {
    if(low < high) {
        int pivot = partition(a, low, high);
        quick_sort(a, low, pivot-1);
        quick_sort(a, pivot+1, high);
    }
}

void sort(int a[], int n) {
    quick_sort(a, 0, n-1);
}

int main() {
    int a[10] = {9,0,1,4,7,2,8,3,5,6};

    print_array(a, 10);
    sort(a, 10);
    print_array(a, 10);
    return 0;
}