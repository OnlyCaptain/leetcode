#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int size = tree.size(), left = 0, right = 0, count = 0, type1 = -1, type2 = -1, count1 = 0, count2 = 0;
        for (right = 0; right < size; right ++) {
            if (type1 == -1) {
                type1 = tree[right];
            }
            else if (type1 != tree[right] && type2 == -1) {
                type2 = tree[right];
            }
            else if (type1 != tree[right] && type2 != tree[right]) {
                while (count1 != 0 && count2 != 0) {
                    if (tree[left] == type1)
                        count1 --;
                    else count2 --;
                    left ++;
                }
                if (count1 == 0) {
                    type1 = type2; type2 = tree[right];
                    count1 = count2; count2 = 0;
                }
                else {
                    type2 = tree[right]; count2 = 0;
                }
            }
            count = max(count, right-left+1);
            if (tree[right] == type1) count1 ++;
            else count2 ++;
        }
        return count;
    }
};

int main() {
    unordered_map<int, int> mapping;
    mapping[0] = 1;
    mapping.erase(0);
    cout << mapping.count(0) << endl;
}