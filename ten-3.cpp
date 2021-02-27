#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int MaximumCopy(const std::vector<size_t>&s, size_t C, size_t &start_index, size_t &end_index) {
    // 滑动窗口的思想
    // test case: [1,2,3,5,4]
    // 求出和小于某个数的最大子数组。
    if (C <= 0 || s.size() == 0) {
        start_index = end_index = 0; return 0;
    }
    size_t left = 0, right, sum = 0, minLeft = INT_MAX, size = s.size();
    start_index = end_index = 0;
    for (right = 0; right < size; right ++) {
        sum += s[right];
        while (sum > C) {
            sum -= s[left];
            left ++;
        }
        if (sum <= C) {
            if (C-sum < minLeft) {
                minLeft = C - sum;
                start_index = left; end_index = right;
            }
        }
    }
    return minLeft;
}

int main() {
    vector<size_t> s{1,2,3,5,4};
    // vector<size_t> s{};
    size_t start, end;
    int ans = MaximumCopy(s, 7,start,end);
    cout << start << " " << end << " " << ans << endl;
}
