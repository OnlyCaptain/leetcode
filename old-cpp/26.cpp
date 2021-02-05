#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int i=0, j=1, size = nums.size(), count=1;
    while (j < size) {
        if (nums[j] == nums[i]) 
            j++;
        else {
            nums[i+1] = nums[j];
            i ++;
            j ++;
            count ++;
        }
    }
    return count;
}

int main()
{
    vector<int> sec = {0, 0, 1,1,1,2,2,3,3,4};
    int size = removeDuplicates(sec);
    for (int i:sec)
        cout << i << " ";
    cout << endl;
}