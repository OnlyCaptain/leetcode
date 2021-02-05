#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// how to get Leetcode tests to run approximately 10-40% faster, since they do a lot of print outs.
static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();  // 从某个答案看来的提速方法。

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int> > result;
    int size = nums.size();
    if (size < 4) return result;
    if (size == 4) {
        if (nums[0] + nums[1] + nums[2] + nums[3] == target) 
            result.push_back(nums);
        return result;
    }  
    // return nums[0] + nums[1] + nums[2] + nums[3];
    sort(nums.begin(), nums.end());
    int m, k, i, j;
    for (m = 0; m < size - 3; m ++) {
        while (m > 0 && m < size - 3 && nums[m-1] == nums[m]) 
            m ++;
        for (k = m+1; k < size - 2; k ++) {
            while (k > m+1 && k < size - 2 && nums[k-1] == nums[k])
                k ++;
            i = k + 1;
            j = size - 1;
            while (i < j) {
                int fi = nums[i] + nums[j] + nums[k] + nums[m];
                if (fi == target) {
                    vector<int> tmp;
                    tmp.push_back(nums[m]);
                    tmp.push_back(nums[k]);
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    result.push_back(tmp);
                    i ++;
                    while (i < j && nums[i-1] == nums[i]) 
                        i ++;
                    j --;
                    while (i < j && nums[j+1] == nums[j]) 
                        j --;
                }
                else if (fi < target) {
                    i ++;
                }
                else {
                    j --;
                }
            }
        }
    }
    return result;
}


int main() 
{
    // vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<int> nums = {-1,-5,-5,-3,2,5,0,4};
    vector<vector<int> > result = fourSum(nums, -7);
    for (vector<int> i:result) {
        for (int j:i)
            cout << j << ",";
        cout << endl;
    }   
}