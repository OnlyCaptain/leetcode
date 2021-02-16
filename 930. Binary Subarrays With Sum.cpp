#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> presum;
        presum[0] = 1;
        int size = A.size(), sum = 0, ans = 0;
        for (int i = 0; i < size; i ++) {
            sum += A[i];
            if (presum.count(sum-S)) {
                ans += presum[sum-S];
            }
            presum[sum]++;
        }
        return ans;
    }
};

int main() {

}