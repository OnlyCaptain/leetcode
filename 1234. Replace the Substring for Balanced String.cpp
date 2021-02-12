#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void counter(vector<int>& counts, char a, bool sign) {
        int signal = sign?1:-1;
        switch (a) {
            case 'Q': 
                counts[0] += signal; break;
            case 'W': 
                counts[1] += signal; break;
            case 'E': 
                counts[2] += signal; break;
            case 'R': 
                counts[3] += signal; break;
        }
    }
    bool judgeIfBalance(vector<int>& counts, vector<int>& curWin) {
        for (int i = 0; i < 4; i ++)
            if (counts[i] && curWin[i] < counts[i]) return false;
        return true;
    }
    int balancedString(string s) {
        vector<int> counts(4,0);
        int size = s.size();
        for (int i = 0; i < size; i ++ ) {
            counter(counts, s[i], 1);
        }

        int total = 0, balance, left = 0, right = 0, minLen = size;
        for (auto a:counts) total += a;
        if (total % 4) 
            cout << "error" << endl;
        total /= 4;

        for (int i = 0; i < 4; i ++) {
            counts[i] = (counts[i]-total < 0)?0:(counts[i]-total);
        }
        total= 0;
        for (int i = 0; i < 4; i ++) 
            total += counts[i];
        if (total == 0) return 0; // no extra char
        
        vector<int> curWin(4,0);
        for (right = 0; right < size; right ++) {
            counter(curWin, s[right], 1);
            while (judgeIfBalance(counts, curWin)) {
                minLen = min(minLen, right-left+1);
                counter(curWin, s[left], 0);
                left ++;
            }
        }
        return minLen;
    }
};

int main() {
    
}