#include <iostream>
#include <vector>
#include <stack>
#include <assert.h>
using namespace std;

class Solution {
public:
    int opPriority(char ch) {
        switch(ch) {
            case '*': return 2; 
            case '/': return 2;
            case '+': return 1;
            case '-': return 1;
            case '#': return 0;
            default: cout << "Error "  << ch << endl;
        };
        return -1;
    }
    int executeOP(int n1, int n2, char op) {
        switch (op) {
            case '*': return (n1*n2); 
            case '/': return (n1/n2); 
            case '+': return (n1+n2); 
            case '-': return (n1-n2); 
        }
        cout << "ERROR" << endl;
        return -1;
    }
    int calculate(string s) {
        string strip_s = "";
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] != ' ') strip_s += s[i];
        }
        strip_s += '#';
        int i = 0, size = strip_s.size(), n1, n2; 
        stack<char> op;
        stack<int> num;
        char last_op;
        while (i < size) {
            if (strip_s[i] <= '9' && strip_s[i] >= '0') {
                string tmp = "";
                while (strip_s[i] <= '9' && strip_s[i] >= '0') 
                    tmp += strip_s[i++];
                num.push(stoi(tmp));
                continue;
            }
            if (op.empty() || opPriority(op.top()) < opPriority(strip_s[i])) { op.push(strip_s[i]); i++; continue;}
            
            while (!op.empty() && opPriority(op.top()) >= opPriority(strip_s[i])) {
                last_op = op.top(); op.pop();
                n1 = num.top(); num.pop();
                assert(!num.empty());
                n2 = num.top(); num.pop();
                num.push(executeOP(n2,n1,last_op));
            }
            op.push(strip_s[i]);
            i ++;
        }
        return num.top();
    }
};

int main() {

}