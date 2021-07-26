#include <iostream>

using namespace std;

void print_array(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

//冒泡排序
//从小到大
void bubble_sort(int a[], int n) {
    bool falg;
    for(int i = 0; i < n-1; ++i) {
        falg = false;
        for(int j = 0; j < n-i-1; ++j) {
            if(a[j] > a[j+1]) {
                falg = true;
                swap(a[j], a[j+1]);
            }
        }
        if(falg == false) { //如果已经有序，提前结束循环
            break;
        }
    }

}

int main() {
    int a[10] = {8,6,1,4,2,9,0,3,7,5};
    
    //输出排序前的数组内容
    print_array(a, 10);
    //进行冒泡排序
    bubble_sort(a,10);
    //输出排序后的数组内容
    print_array(a, 10);
    
    return 0;
}