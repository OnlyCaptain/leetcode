#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string subs;
        for (int i = 0; i < s.size(); i ++) {
            if (s.size()%(i+1) == 0) {
                string substr;
                string sub = s.substr(0, i+1);
                for (int j = 0; j < s.size()/(i+1); j ++) {
                    substr += sub;
                }
                if (substr == s) return true;
            }
        }
        return false;
    }
};

int main() {
    string s = "123456";
    cout << s.substr(0,5) << endl;
}