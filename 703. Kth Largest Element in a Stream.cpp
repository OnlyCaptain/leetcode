#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int> nums;
public:
    KthLargest(int k, vector<int>& v):k(k) {
        for (auto item:v) {
            nums.push(item);
            if (nums.size() > k) nums.pop();
        }
    }
    
    int add(int val) {
        nums.push(val);
        if (nums.size() > k) nums.pop();
        return nums.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main() {
    vector<int> v{1,3,2,8,5,4};
    priority_queue<int, vector<int>, greater<int>> dq;
    for (auto item:v)  dq.push(item);
    cout << endl;
    while (!dq.empty()) {
        cout << "pop: " << dq.top() << endl; dq.pop();
    }
    cout << endl;
}