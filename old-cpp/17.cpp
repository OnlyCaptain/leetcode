#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string tele[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits == "") return result;
    int size = digits.size();
    stack<string> store, tmp;
    string cur="", head="", add="";
    cur = tele[digits[0]-'0'];
    // cout << cur << endl;
    // for (int i = 0; i < cur.size(); i ++) 
    //     cout << cur[i] << ", ";
    // cout << endl;
    for (int i = 0; i < cur.size(); i ++) {
        add = "";
        add += cur[i];
        // add = "" + cur[i];
        store.push(add);
    } 
    for (int i = 1; i < size; i ++) {
        cur = tele[digits[i]-'0'];
        stack<string> tmp;
        while (!store.empty()) {
            head = store.top();
            store.pop();
            for (int i = 0; i < cur.size(); i ++) {
                add = head + cur[i];
                tmp.push(add);
            }
        }
        store = tmp;
    }
    while (!store.empty()) {
        result.push_back(store.top());
        store.pop();
    }
    return result;
}


int main()
{
    vector<string> result;
    result = letterCombinations("23");
    for (string i:result)
        cout << i << ", ";
    cout << endl;
    // vector<string> result;
    result = letterCombinations("");
    for (string i:result)
        cout << i << ", ";
    cout << endl;
}