#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int size = A.size();
        int b = 0;
        for (int i = 1; i < size; i ++) {
            if (A[i] == A[i-1]) continue;
            if (b == 0) {
                b = A[i] - A[i-1] > 0?1:-1;
            }
            if (A[i] > A[i-1] && b > 0) continue;
            if (A[i] < A[i-1] && b < 0) continue;
            return false;
        }
        return true;
    }
};

int main() {

}