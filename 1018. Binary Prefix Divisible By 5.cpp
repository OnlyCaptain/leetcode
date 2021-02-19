#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int size = A.size(), sum = 0;
        vector<bool> ans;
        if (size == 0) return ans;
        for (int i = 0; i < size; i ++) {
            ans.push_back((sum = (sum*2 + A[i])%5) == 0);
        }
        return ans;
    }
};

int main() {

}