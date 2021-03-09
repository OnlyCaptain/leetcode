#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0, ans = 0, gap = 0;
        for (auto it:nums) sum += it;
        if (sum < goal) {
            gap = goal - sum;
            ans = (gap%limit==0)?(gap/limit):(gap/limit+1);
        }
        else if (sum > goal) {
            gap = sum - goal;
            ans = (gap%limit==0)?(gap/limit):(gap/limit+1);
        }
        return ans;
    }
};

int main() {

}
[1,-10,9,1]
100
0