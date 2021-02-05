#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	deque<int> mindeque;
	deque<int> maxdeque;

	int longestSubarray(vector<int>& nums, int limit) {
		int left = 0;
		int right = 0;
		int best = 1;

		while (right < nums.size()) {
			push(nums[right]);
			int mini = mindeque.front();
			int maxi = maxdeque.front();

			if (maxi - mini <= limit) {
				best = max(best, right - left + 1);
			}
			else {
				pop(nums[left]);
				left++;
			}

			right++;
		}

		return best;
	}

	void pop(int x) {
		if (mindeque.front() == x) {
			mindeque.pop_front();
		}
		if (maxdeque.front() == x) {
			maxdeque.pop_front();
		}
	}

	void push(int x) {
		while (!mindeque.empty() && mindeque.back() > x) {
			mindeque.pop_back();
		}
		mindeque.push_back(x);
		while (!maxdeque.empty() && maxdeque.back() < x) {
			maxdeque.pop_back();
		}
		maxdeque.push_back(x);
	}
}; 

int main() {
	Solution a;
	vector<int> nums = { 8,2,4,7 };
	int limit = 4;
	int ans = a.longestSubarray(nums, limit);
	cout << ans << endl;
}