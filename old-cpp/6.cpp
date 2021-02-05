#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1) return s;
    vector<string> zig(numRows, "");
    int k = 0, E = 1;
    for (int i = 0; i < s.size(); i ++) {
        // cout << zig[k] << " | " << s[i] << endl;
        zig[k] += s[i];
        k += E;
        if (k >= numRows || k <= -1) {
            k -= E;
            E = -E;
            k += E;
        }
    }
    // cout << "a" << endl;
    // __assert();
    // assert(zig.size() != 0);
    string result;
    for (int i = 0; i < numRows; i ++) {
        result += zig[i];
    }
    return result;
}


int main() 
{
    cout << convert("PAYPALISHIRING", 3) << endl;
    cout << convert("PAYPALISHIRING", 4) << endl;
    cout << convert("AB", 1) << endl;
}