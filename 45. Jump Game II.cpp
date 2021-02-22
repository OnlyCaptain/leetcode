#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int path = 0, maxReach = 0, lastMaxJump = 0;
        for (int i = 0; i < size; i ++) {
            if (i == size-1) return path;
            maxReach = max(maxReach, i + nums[i]);
            if (i == lastMaxJump) {
                path += 1;
                lastMaxJump = maxReach;
            }
        }
        return path;
    }
};

int main() {

}