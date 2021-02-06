#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string str = "1";
        int stri = 0, sizei = 0, last = 1, count = 0;
        while (str.length() < n) {
            stri += str[sizei] - '0';
            sizei ++;
            if (stri == str.length()) {
                last = last % 2 + 1;
                str += last + '0';
                if (str[sizei] == '2') 
                    str += last + '0';
            }
        }
        for (int i = 0; i < str.length(); i ++) 
            if (str[i] == '1') 
                count ++;
        return count;
    }
};

int main() {

}