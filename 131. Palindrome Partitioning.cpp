#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<vector<bool>> f;
    vector<vector<string>> ans;
    vector<string> sub;
public:
    void dfs(string& s, int index) {
        if (index == s.size()) {
            ans.push_back(sub);
            return;
        }
        for (int i = index; i < s.size(); i ++) {
            if (f[index][i]) {
                sub.push_back(s.substr(index, i-index+1));
                dfs(s, i+1);
                sub.pop_back();
            }
        } 
    }
    vector<vector<string>> partition(string s) {
        int size = s.size();
        f.assign(size+1, vector<bool>(size+1, true));

        for (int i = size-1; i >= 0; i --) {
            for (int j = i+1; j < size; j ++) {
                if (f[i+1][j-1] && s[i] == s[j]) f[i][j] = true;
                else f[i][j] = false;
            }
        }

    }
};

int main() {

}