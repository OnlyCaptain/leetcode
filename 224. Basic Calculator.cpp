#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<char> op;
        stack<int> num;
        string strip_S = "(";
        for (auto i:s) {
            if (i == ' ') continue;
            strip_S += i;
        }
        strip_S += ')';
        
        int i = 0, size = strip_S.size();
        while (i < size) {
            if (strip_S[i] <= '9' && strip_S[i] >= '0') {
                if (i > 0 && strip_S[i-1] == '(') op.push('+');
                string tmp = "";
                while (strip_S[i] <= '9' && strip_S[i] >= '0') tmp += strip_S[i++];
                num.push(stoi(tmp));
                continue;
            }
            switch (strip_S[i]) {
                case ' ': i++; break;
                case '(': {
                    if (i > 0 && strip_S[i-1] == '(') op.push('+');
                    op.push('(');
                    i ++; break;
                } 
                case '+': op.push('+'); i ++; break;
                case '-': op.push('-'); i ++; break;
                case ')': 
                    int tmp, sub = 0;
                    char tmp_op;
                    tmp_op = op.top(); op.pop();
                    while (tmp_op != '(') {
                        tmp = num.top(); num.pop();
                        switch(tmp_op) {
                            case '+': sub += tmp; break;
                            case '-': sub -= tmp; break;
                        }
                        tmp_op = op.top(); op.pop();
                    }
                    if (tmp_op == '(') num.push(sub);
                    i ++;
                    break;
            }
        }
        return num.top();
    }
};

int main() {

}