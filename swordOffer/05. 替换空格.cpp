#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for (auto i:s) {
            if (i == ' ') {
                ans += "%20";
            }
            else ans += i;
        }
        return ans;
    }
};

int main() {

}

