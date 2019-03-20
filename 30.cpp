#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    
}

int main()
{
    vector<int> result;
    vector<string> words = {"foo", "bar"};
    string s = "barfoothefoobarman";
    result = findSubstring(s, words);
    for (int i:result) 
        cout << i << ",";
    cout << endl;
}