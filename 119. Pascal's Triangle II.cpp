#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);
        // cni = cni-1 * (n-i+1)/i
        for (int i = 1; i <= rowIndex; i ++) {
            ans[i] = ans[i-1]*(rowIndex-i+1)/i;
        }
        return ans;
    }
};

int main() {

}