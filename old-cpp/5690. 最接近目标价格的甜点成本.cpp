#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        bitset<20005> f;
        for (auto i:baseCosts) f[i] = 1;
        for (auto i:toppingCosts) f |= (f<<i) | (f<<(i*2));
        int ans = -20004;
        for (int i = 0; i < 20005; i ++) {
            if (f[i] && abs(i-target) < abs(ans-target)) ans = i;
        }
        return ans;
    }
};

int main() {

}