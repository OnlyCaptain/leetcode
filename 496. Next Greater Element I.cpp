#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        if (nums2.size() == 0) return ans;
        stack<int> st;
        map<int,int> mapping;
        for (int i = nums2.size()-1; i >= 0; i --) {
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            if (st.empty()) mapping[nums2[i]] = -1;
            else mapping[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i ++) {
            ans[i] = mapping[nums1[i]];
        }
        return ans;
    }
};

int main() {

}