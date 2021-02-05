#include <iostream>
#include <stack>
using namespace std;


char corres(char ch) {
    switch (ch) {
        case '(':
            return ')';
            break;
        case '{':
            return '}';
            break;
        case '[':
            return ']';
            break;
        default: 
            return '*';
            break;
    }
    return '*';
}

bool isValid(string s) {
    int size = s.size();
    char cur;
    stack<char> chara;
    for (int i = 0; i < size; i ++) {
        cur = s[i];
        if (cur == '(' || cur == '{' || cur == '[') {
            chara.push(cur);
        }
        else {
            if (chara.empty()) return false;
            if (corres(chara.top()) != cur) 
                return false;
            else  chara.pop();
        }
    }
    if (chara.empty()) return true;
    return false;
}

int main()
{
    cout << isValid("()") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(]") << endl;
    cout << isValid("([)]") << endl;
    cout << isValid("{[]}") << endl;
    cout << isValid("]") << endl;
}  