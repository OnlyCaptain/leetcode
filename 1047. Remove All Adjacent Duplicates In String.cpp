#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (int i = 0; i < S.size(); i ++) {
            if (!st.empty() && S[i] == st.top()) {
                st.pop();
            }
            else st.push(S[i]);
        }
        int size = st.size();
        string ans(size, '0');
        for (int i = size-1; i >= 0; i --) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};

int main() {

}