#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        if (A.size() == 0) return -1;
        int left = 0, right, size = A.size(), ans = INT_MAX, sum = 0;
        deque<int> presum, indexes;
        presum.push_back(0);
        indexes.push_back(-1);
        for (right = 0; right < size; right ++) {
            if (A[right] >= K) return 1;
            sum += A[right];
            if (!presum.empty() && presum.front() > sum) {
                presum.pop_front(); presum.push_front(sum);
            }
            while (!presum.empty() && presum.back() > sum) {
                presum.pop_back();
                indexes.pop_back();
            }
            presum.push_back(sum);
            indexes.push_back(right);
            auto it = upper_bound(presum.begin(), presum.end(), sum-K);
            if (it != presum.begin()) {
                int target = it - presum.begin();
                target = indexes[target-1]; 
                ans = min(ans, right-target);
            } 
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};


int main() {

}