#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int size = nums.size();
    if (size < 3) return 0; 
    sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2], i, j, sum, fi, se;
    int diff = abs(closest - target);
    vector<vector<int> > result;
    for (int m = 0; m < size - 2; m ++) {
        // while (m > 0 && m < size - 2 && nums[m-1] == nums[m])
        //     m ++;
        i = m + 1;
        j = size - 1;
        fi = nums[m];

        while (i < j) {
            se = fi + nums[i] + nums[j];
            if (se > target) {
                j --;
                // while (i < j && nums[j] == nums[j+1])
                //     j --;
            }
            else if ( se < target) {
                i ++;
                // while (i < j && nums[i] == nums[i-1])
                //     i ++;
            }
            else {
                return se;
            }
            if (abs(se - target) < diff) {
                closest = se;
                diff = abs(se-target);
            }
        }
    }
    return closest;
}



int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    cout << threeSumClosest(nums, 1) << endl;
}