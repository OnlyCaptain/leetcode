#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string_view>

using namespace std;

class Solution {
public:
    int lenCommonPrefix(string_view& arr1, string_view& arr2) {
        int len = 0;
        while (len < arr1.size() && len < arr2.size() && arr1[len] == arr2[len])
            len ++;
        return len;
    }
    string longestDupSubstring(string s) {
        int size = s.size();
        string_view SV(s);
        vector<string_view> arr;
        for (int i = 0; i < size; i ++)
            arr.push_back(SV.substr(i));
        sort(arr.begin(), arr.end());

        int maxLen = 0;
        string ans = 0;
        for (int i = size-1; i > 0; i --) {
            if (maxLen > arr[i].size() || maxLen > arr[i-1].size()) continue;
            int len = lenCommonPrefix(arr[i], arr[i-1]);
            if (len > maxLen) {
                maxLen = len;
                ans = arr[i].substr(0, len);
            }
        }
        return ans;
    }
};

int main() {
    string s = "0123456";
    string_view sv(s);
    // cout << s.substr(1,2) << endl;
    for (int i = 0; i < sv.size(); i ++) {
        cout << sv.substr(i) << endl;
    }

}