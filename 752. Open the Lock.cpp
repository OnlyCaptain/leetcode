#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> seen;
        if (dead.count("0000")) return -1;
        seen.insert("0000");
        q.push("0000");
        int res = -1;
        while (!q.empty()) {
            int size = q.size();
            res ++;
            for (int i = 0; i < size; i ++) {
                string cur = q.front(); q.pop();
                if (cur == target) 
                    return res;

                for (int j = 0; j < cur.length(); j ++) {
                    string up = cur;
                    string down = cur; 
                    up[j] = (up[j] == '9')?'0':(up[j]+1);
                    down[j] = (down[j] == '0')?'9':(down[j]-1);
                    cout << up << " && " << down << endl;
                    if (!dead.count(up) && !seen.count(up)) q.push(up), seen.insert(up);
                    if (!dead.count(down) && !seen.count(down)) q.push(down), seen.insert(down);
                }
                
            }
        }
        return -1;
    }
};
int main() {

}