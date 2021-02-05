#include <string>
#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
    if (needle == "") return 0;
    int size = haystack.size();
    for (int i = 0; i < size; i ++) {
        if (haystack[i] == needle[0]) {
            int j;
            for (j = 0; j < needle.size(); j ++) {
                if (i + j >= size) return -1;
                if (haystack[i+j] != needle[j]) break;
            }
            if (j == needle.size()) 
                return i;
        }
    }
    return -1;
}

int main()
{
    cout << strStr("hello", "ll") << endl;
    cout << strStr("aaaaaa", "bba") << endl;
}
