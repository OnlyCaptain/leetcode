#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        // bool ans = true;
        int sign = n%2;
        n >>= 1;
        while (n > 2) {
            if (n%2 == sign) return false;
            sign = !sign;
            n >>= 1;
        }
        return true;
    }
};

int main() {
    int n = 5, sign = 1;
    cout << !sign << endl;
    cout << !(!sign) << endl;
}