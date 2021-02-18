#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int size = A.size(), res = 0;
        queue<int> flip;
        // flip 存放的是每次翻转最后一位的位置
        // flip.size() 就代表了当前位置下所经历过的flip次数
        // 显然当前位置为0时，应该有偶数次+1的翻转才能为1
        // 当前位置为1时，应该有奇数次+1的翻转才能为1
        for (int i = 0; i < size; i ++) {
            if (A[i] == 0 && flip.size()%2 == 0 || A[i] == 1 && flip.size()%2 == 1) {
                res ++;
                if (i + K > size) return -1;
                flip.push(i+K-1);
            }
            if (flip.front() == i) {
                flip.pop();
            }
        }
        return res;
    }
};

int main() {

}