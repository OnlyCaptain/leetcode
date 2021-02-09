#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    int findno(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        int j=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            hashmap[nums[i]]++;
            while(hashmap.size()>k)
            {
                hashmap[nums[j]]--;
                if(hashmap[nums[j]]==0)
                    hashmap.erase(nums[j]);
                j++;
            }
            count=count+i-j+1;
            cout << count << " ";

        }
        cout << endl;
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        cout << findno(nums,k) <<endl;
        cout << findno(nums,k-1) << endl;
        return findno(nums,k)-findno(nums,k-1);
    }
};

int main() {
    Solution a;
    vector<int> nums{1,2,1,2,3};
    a.subarraysWithKDistinct(nums, 2);
}