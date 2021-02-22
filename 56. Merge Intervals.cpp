#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // struct cmp {
        //     bool operator()(vector<int> a, vector<int> b) {
        //         if (a[0] < b[0] || a[0] == b[0] && a[1] <= b[1]) return true;
        //         return false;
        //     }
        // };
        vector<vector<int>> ans;
        int size = intervals.size(), left = -1, right = -1;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < size; i ++) {
            if (left == -1) {
                left = intervals[i][0]; right = intervals[i][1];
                continue;
            }
            if (right >= intervals[i][1]) continue;
            if (right >= intervals[i][0] && right < intervals[i][1]) right = intervals[i][1];
            if (right < intervals[i][0]) {
                ans.push_back(vector<int>{left, right});
                left = intervals[i][0]; right = intervals[i][1];
            }
        }
        ans.push_back(vector<int>{left, right});
        return ans;
    }
};

int func(int a) {return a;}
double func(double b) {return b;}

int main() {

}