#include <iostream>

using namespace std;

void print_array(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int a[], int low, int middle, int high) {
    int i = low, j = middle + 1;
    int len = high-low+1;
    int tmp[len] = {0};
    int k = 0;
    while(i <= middle && j <= high) {
        if(a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }

    if(i <= middle) {
        for(int l = i; l <= middle; ++l) {
            tmp[k++] = a[l];
        }
    }

    if(j <= high) {
        for(int l = j; l <= high; ++l) {
            tmp[k++] = a[l];
        }
    }

    for(int l = 0; l < len; ++l){
        a[low++] = tmp[l];
    }
}

void merge_sort(int a[], int low, int high) {
    if(low < high) {
        int middle = low + (high - low) /2;
        merge_sort(a, low, middle);
        merge_sort(a, middle+1, high);
        merge(a, low, middle, high);
    }
}

void sort(int a[], int n) {
    merge_sort(a, 0, n-1);
}

int main() {
    int a[10] = {9,0,1,4,7,2,8,3,5,6};

    print_array(a, 10);
    sort(a, 10);
    print_array(a, 10);
    return 0;
}