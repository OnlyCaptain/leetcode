#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void printV(vector<int>& nums) {
    for (int i:nums) {
        cout << i << " ";
    }
}

void printVV(vector<vector<int> >& r) {
    for (vector<int> i:r) {
        for (int j:i) 
            cout << j << ',';
        cout << endl;
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int m = 0, i, j, size = nums.size();
    int fi, se, th;
    vector<vector<int> >::iterator it;
    vector<vector<int> > result;
    for (m = 0; m < size - 2; m ++) {
        while(m > 0 && m < size - 2 && nums[m] == nums[m-1]){
            m ++; 
        }   // skip duplicate.
        
        i = m + 1;
        j = size - 1;
        fi = nums[m];
        while ( i < j ) {
            se = nums[i] + nums[j];
            if (fi + se < 0) 
                i ++;
            else if (fi + se == 0) {
                vector<int> tmp;
                tmp.push_back(fi);
                tmp.push_back(nums[i]);
                tmp.push_back(nums[j]);
                i ++;
                while (i < j && nums[i-1] == nums[i]) 
                    i ++;
                j --;
                while (i < j && nums[j] == nums[j+1])
                    j --;
                // skip duplicate.
                // it = find(result.begin(), result.end(), tmp);
                // if (it == result.end())
                result.push_back(tmp);
            }
            else 
                j --;
        }
    }
    return result;
}

vector<vector<int>> threeSum1(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	int n = nums.size();

	for(int i=0; i<n-2; i++){
		while(i > 0 && nums[i] == nums[i-1] && i < n-2){
			i++;
			// skip duplicate
		}
		int j = i+1;
		int k = n-1;
		while(j < k){
			if(nums[i] + nums[k] + nums[j] == 0){
				vector<int> sol{nums[i], nums[j], nums[k]};
				res.push_back(sol);
				j++;
				while(j<k && nums[j-1] == nums[j]){
                    j++;
                }
                k--;
                while(j<k && nums[k+1] == nums[k]){
                    k--;
                }
			}else if(nums[i] + nums[k] + nums[j] > 0){
				k--;
			}else{
				j++;
			}
		}
	}

	return res;
}

int main()
{
    vector<int> nums = {
        -1, 0, 1, 2, -1, -4
    };
    // vector<int> nums;
    vector<vector<int> > result = threeSum(nums);
    printVV(result);
    return 0;

    // printV(nums);
    // cout << endl; 
}