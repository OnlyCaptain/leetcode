#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int judgeIfMore(vector<int>& op, int target) {
        sort(op.begin(), op.end(), greater<int>());
        int i = 0;
        for (; i < op.size(); i ++) {
            target -= op[i];
            if (target <= 0) return i+1;
        }
        if (target <= 0) return i+1;
        return -1;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        for (auto i:nums1) sum1 += i;
        for (auto i:nums2) sum2 += i;
        if (sum1 == sum2) return 0;
        vector<int>& less = (sum1>sum2)?nums2:nums1;
        vector<int>& great = (sum1>sum2)?nums1:nums2;
        int maxx = max(sum1, sum2), minn = min(sum1, sum2);
        // 要使两个数组和相等，无非就是大的执行减小操作，小的执行增大操作
        // 可以表示为： maxx - op1 = minn + op2
        // 那么只需要收集op，使得： maxx - minn == op1 + op2，也就是从op里面选出最少的操作，一次排序即可
        vector<int> op;
        for (auto i:less) op.push_back(6-i);
        for (auto i:great) op.push_back(i-1);
        return judgeIfMore(op, maxx-minn);
    }
};

int main() {

}