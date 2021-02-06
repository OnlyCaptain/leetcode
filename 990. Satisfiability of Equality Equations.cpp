#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    struct union_find {
        vector<int> id, rank;
        union_find(int n): id(n), rank(n, 1) {
            for (int i = 0; i < id.size(); i ++) id[i] = i;
        }
        int find(int p) {
            while (p != id[p]) {
                id[p] = id[id[p]];
                p = id[p];
            }
            return p;
        }
        void connect(int id1, int id2) {
            int f1 = find(id1), f2 = find(id2);
            if (f1 != f2) {
                if (rank[f1] > rank[f2]) {
                    id[f1] = f2;
                    rank[f2] += rank[f1];
                }
                else {
                    id[f2] = id[f1];
                    rank[f1] += rank[f1]; 
                }
            }
        }
        bool is_connected(int id1, int id2) {
            return find(id1) == find(id2);
        }
    };
    
    bool equationsPossible(vector<string>& equations) {
        union_find uf(26);
        for (string equa:equations) {
            if (equa[1] == '=' && !uf.is_connected(equa[0]-'a', equa[3]-'a')) 
                uf.connect(equa[0]-'a', equa[3]-'a');
        }
        for (string equa:equations) {
            if (equa[1] == '!' && uf.is_connected(equa[0]-'a', equa[3]-'a'))
                return false;
        }
        return true;
    }
};
int main() {

}