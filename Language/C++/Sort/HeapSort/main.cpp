#include <iostream>

using namespace std;

void print_array(int a[], int n);
void heapify(int a[], int i, int n);
void heap_sort(int a[], int n);

void print_array(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void heapify(int a[], int i, int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left < n && a[left] > a[largest]){
        largest = left;
    }

    if(right < n && a[right] > a[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

void heap_sort(int a[], int n) {
    //构建大顶堆
    for(int i = n/2; i >= 0; --i) {
        heapify(a, i, n);
    } 

    for(int i = n-1; i > 0; --i) {
        swap(a[i], a[0]);
        heapify(a, 0, i);
    }
}

int main() {
    int a[10] = {9,0,1,4,7,2,8,3,5,6};

    print_array(a, 10);
    heap_sort(a, 10);
    print_array(a, 10);

    return 0;
}