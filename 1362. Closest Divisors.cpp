#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int ex = (int)sqrt(num+2);
        vector<int> ans;
        for (int i = ex; i > 0; i --) {
            if ((num+2) % i == 0) {
                ans.push_back(i);
                ans.push_back((num+2)/i);
                return ans;
            }
            else if ((num+1) % i == 0) {
                ans.push_back(i);
                ans.push_back((num+1)/i);
                return ans;
            }
        }
        return ans;
    }
};

int main() {
    cout << (int)sqrt(999) << endl;
}