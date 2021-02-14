#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) continue;
            int last = nums[i], tmp;
            while (last != 0) {
                tmp = nums[last-1];
                nums[last-1] = 0;
                last = tmp;
            }
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != 0) ans.push_back(i+1);
        }
        return ans;
    }
};

int main() {

}