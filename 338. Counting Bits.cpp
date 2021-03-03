#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for (int i = 1; i <= num; i ++) {
            ans[i] = ans[i>>1]+(i%2);
        }
        return ans;
    }
};

int main() {

}