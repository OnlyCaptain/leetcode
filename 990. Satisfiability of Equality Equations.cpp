#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool judge(bool ifequal, int arg1, int arg2) {
        if (ifequal) return (arg1 == arg2);
        else return (arg1 != arg2);
    }
    bool equationsPossible(vector<string>& equations) {
        int size = equations.size();
        unordered_map<char, int> variables;
        for (int i = 0; i < size; i ++) {
            string cur = equations[i];
            bool ifequal = cur.substr(1,2) == "==" ? true : false;
            if (variables.count(cur[0])) {
                if (!variables.count(cur[3])) variables[cur[3]] = ifequal? variables[cur[0]] : variables[cur[0]] + 1;
                else if (!judge(ifequal, variables[cur[0]], variables[cur[3]])) 
                    return false;
            }
            else {
                if (ifequal) variables[cur[0]] = variables[cur[3]];
                else variables[cur[0]] = variables[cur[3]] + 1;
            }
        }
        return true;
    }
};

int main() {

}