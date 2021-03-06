#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, -1);
        if (size == 0) return ans;
        stack<int> st;
        for (int i = size-1; i >= 0; i --) st.push(nums[i]);
        for (int i = size-1; i >= 0; i --) {
            while (!st.empty() && st.top() <= nums[i]) st.pop();
            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};


int main() {

}