#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int maxx = INT_MIN, minn = INT_MAX;
        for (size_t i = 0; i < nums.size(); i ++) {
            if (nums[i]%2 != 0) nums[i] *= 2;
            maxx = max(maxx, nums[i]);
            minn = min(minn, nums[i]);
        }
        int min_deviation = maxx - minn;

        priority_queue<int> task;
        for (auto i: nums)
            task.push(i);
        
        while(task.top() % 2 == 0) {
            int top = task.top(); task.pop();
            min_deviation = min(min_deviation, top-minn);
            top /= 2;
            minn = min(minn, top);
            task.push(top);
        }
        min_deviation = min(min_deviation, task.top()-minn);
        return min_deviation;
    }
};

int main()
{
    cout << -1%2 << endl;
}