#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size = arr.size();
        if (size == 1) return 1;
        vector<char> signArr(size-1);
        for (int i = 0; i < size-1; i ++) 
            signArr[i] = arr[i] == arr[i+1]?'=':(arr[i]>arr[i+1]?'>':'<');
        int maxLen = 0, len = 0;
        for (int i = 0; i < signArr.size(); i ++) {
            if (signArr[i] == '=') {
                maxLen = max(maxLen, len);
                len = 0;
            }
            else {
                len ++;
                if (i == signArr.size()-1 || signArr[i] == signArr[i+1]) {
                    maxLen = max(maxLen, len);
                    len = 0;
                }
            }
        }
        return maxLen+1;
    }
};