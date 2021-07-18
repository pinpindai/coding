#include <iostream>
#include <vector>
#include <string>

using namespace std;

int g_min = INT_MAX;

//dp
void recursion(int a[][4]) {
    //定义状态
    int dp[4] = {0};

    //初始化状态值
    for(int i = 0; i < 4; ++i) {
        dp[i] = a[3][i];
    }

    for(int i = 2; i >= 0; --i) {
        for(int j = 0; j <= i; ++j) {
            dp[j] = min(dp[j], dp[j+1]) + a[i][j];
        }
    }

    cout << "result = " << dp[0] << endl;
}

//暴力递归
void recursion1(int a[][4], int i, int j, string path, int sum) {

    path = path + to_string(a[i][j]);
    sum = sum + a[i][j];

    //1、判断递归是否结束
    if(i == 3) {
        g_min =  g_min > sum ? sum : g_min;
        path += " #, with sum = " + to_string(sum);
        cout << path << endl;
        return;
    }

    //2、本层处理逻辑
    path += "->";

    //3、递归
    recursion1(a, i+1, j, path, sum);
    recursion1(a, i+1, j+1, path, sum);

    //4、重置状态(如果需要的话)
}

int main() {
    int a[4][4] = { 
        {2}, 
        {3,4}, 
        {6,5,7},
        {4,1,8,3} };

    // string path = "";
    // recursion1(a, 0, 0, path, 0);
    // cout << "the min result = " << g_min << endl;

    recursion(a);

    return 0;
}