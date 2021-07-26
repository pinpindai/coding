#include <iostream>

using namespace std;

void print_array(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

//选择排序
//从小到大
void select_sort(int a[], int n) {
    int min;
    for(int i = 0; i < n-1; ++i) { //每次遍历，都找剩下的数据中的最小值
        min = i;
        for(int j = i+1; j < n; ++j) {
            if(a[min] > a[j]) {
                min = j;
            }
        }
        if(min != i) {
            swap(a[min], a[i]);
        }
    }
}

int main() {
    int a[10] = {9,0,1,5,2,4,8,7,3,6};
    //打印排序前的数组内容
    print_array(a, 10);
    //排序
    select_sort(a, 10);
    //打印排序后的数组内容
    print_array(a, 10);
    return 0;
}