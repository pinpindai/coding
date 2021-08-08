#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result; //用来存放所有符合条件的结果
vector<int> path; //用来存放符合条件的结果

//1、确定回溯函数的参数和返回值
void backTracking(vector<int>& nums, int startIndex) {
    //2、递归终止条件判断
    if(startIndex == nums.size()) {
        //保存结果
        result.push_back(path);
        return;
    }

    //3、本层处理逻辑
    for(int i = startIndex; i < nums.size(); ++i) {
        path.push_back(nums[i]); //处理节点
        backTracking(nums, startIndex+1); //递归--注意startIndex是否需要+1
        path.pop_back();//回溯--撤销节点处理
    }
}

int main() {
    result.clear();
    path.clear();
    vector<int> nums;
    backTracking(nums, 0);

    return 0;
}