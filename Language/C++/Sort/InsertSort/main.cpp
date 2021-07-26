#include <iostream>

using namespace std;

void print_array(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

//插入排序
//从小到大
void insert_sort(int a[], int n) {
    int cur;
    for(int i = 1; i < n; ++i) {
        cur = a[i];
        int j = i-1;
        while(j >= 0 && cur < a[j]) {
            a[j+1] = a[j]; //往后移一位
            --j;
        }
        a[j+1] = cur;
    }
}

int main() {
    int a[10] = {9,0,1,4,7,2,8,3,5,6};

    print_array(a, 10);
    insert_sort(a, 10);
    print_array(a, 10);
    return 0;
}