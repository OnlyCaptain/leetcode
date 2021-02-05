#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int maxh=0, maxv=0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for (int i = 1; i < h; i ++) {
            maxh = max(maxh, horizontalCuts[i] - horizontalCuts[i-1]);
        }       
        for (int i = 1; i < w; i ++) {
            maxv = max(maxv, verticalCuts[i] - verticalCuts[i-1]);
        }
        return maxh*maxv % 1000000007;
    }
};


int main() {
    vector<int> h = {3,1};
    vector<int> w = {1};
    Solution a;
    cout << a.maxArea(5,4,h,w) << endl;
    // sort(a.begin(), a.end());
    // for (auto i:a)
        // cout << i << " ";
}