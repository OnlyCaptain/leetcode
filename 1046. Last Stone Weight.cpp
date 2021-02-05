#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> task;
        for (auto i:stones) {
            task.push(i);
        }
        while(task.size() > 1) {
            int m1,m2;
            m1 = task.top();
            task.pop();
            m2 = task.top();
            task.pop();
            if (m1-m2 != 0) task.push(m1-m2);
        }
        if(task.size() == 0) return 0;
        else return task.top();
    }
};

int main() {
    vector<int> stones = {1,8,3,4};
    priority_queue<int> stones2;
    // sort(stones.begin(), stones.end(), greater<int>());
    for (int i = 0; i < stones.size(); i ++)  {
        cout << stones[i] << " ";
        stones2.push(stones[i]);
    }
    cout << endl;
    while (!stones2.empty()) {
        cout << stones2.top() << " ";
        stones2.pop();
    }
    
    // cout << stones << endl;
}