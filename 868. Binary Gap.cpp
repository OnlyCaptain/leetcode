#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int count = 0, cur = 0, last = -1;
        while (n >= 2) {
            if (n%2 == 0) cur ++;
            else {
                if (last == -1) {
                    last = 0;
                    cur = 0;
                }
                else {
                    count = max(count, cur+1);
                    cur = 0;
                }
            }
            n >>= 1;
        }
        if (n && !last) {
            count = max(count, cur+1);
        }
        return count;
    }
};

int main() {

}