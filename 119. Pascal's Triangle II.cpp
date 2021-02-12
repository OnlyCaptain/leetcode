#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int permutation(int n, int k) {
        double ans = 1;
        if (k == 0 && n == 0 || n == k || k == 0) return 1;
        if (k > n || n <= 0 || k <= 0) return 0;
        int numerator = max(k, n-k), denominator = min(k, n-k);
        if (k == 14) cout << numerator << " " << denominator << endl;
        for (int i = n, j = 1; i > numerator || j <= denominator;) {
            if (i > numerator) {
                ans *= i;
                i --;
            } 
            if (j <= denominator) {
                ans /= j;
                j ++;
            } 
        }
        return (int)ans;
    }
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