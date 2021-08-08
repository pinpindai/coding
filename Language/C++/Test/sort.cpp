#include <iostream>

using namespace std;

void print_array(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void heapify(int a[], int i, int n) {
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if(left < n && a[largest] < a[left])
        largest = left;
    if(right < n && a[largest] < a[right])
        largest = right;
    
    if(i != largest) {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

void heapSort(int a[], int n) {
    for(int i = n/2; i >=0; --i) {
        heapify(a, i, n);
    }

    for(int i = n-1; i > 0; --i) {
        swap(a[i], a[0]);
        heapify(a, 0, i);
    }
}

void sort(int a[], int n) {
    heapSort(a, n);
}

int main() {
    int a[10] = {9,0,1,4,7,2,8,3,5,6};

    print_array(a, 10);
    sort(a, 10);
    print_array(a, 10);
    return 0;
}