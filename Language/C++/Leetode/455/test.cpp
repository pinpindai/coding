#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int index = s.size()-1;
        for(int i = g.size()-1; i >= 0; --i) {
            if(index >= 0 && s[index] >= g[i]) {
                cout << index << ", " << i << endl;
                ++res;
                --index;
            }
        }

        return res;
    }

int main() {
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};

    cout <<  findContentChildren(g, s) << endl;
    return 0;
}