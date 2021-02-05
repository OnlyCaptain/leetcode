#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0, ans = 0, curK = K, size = A.size();
        for (right = 0; right < size; right ++) {
            if (A[right] == 0) {
                if (curK > 0) {
                    curK --;
                    ans = max(ans, right-left+1);
                } 
                else {
                    while (A[left] == 1) left ++;
                    left ++;
                }   
                
            }
            else ans = max(ans, right-left+1);
        }
        return ans;
    }
};

int main() {

}