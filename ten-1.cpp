#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printAllSubset(vector<int> nums) {
    int size = nums.size();
    // vector<vector<int>> ans;
    cout << "[]" << endl;
    if (size == 0) return;
    // 局限性：size 超大的时候可能会溢出，但是小规模数据时具有比较好的性能。
    long limit = 1 << size;
    for (int i = 0; i < limit; i ++) {
        cout << "["; 
        for (int j = 0; j < size; j ++) {
            long mask = 1 << j;
            if (mask & i) cout << nums[j] << " ";
        }
        cout << "]";
        cout << endl;
    }
}

int main() {
    vector<int> test1{1,2,3,4,5,6,7,8,9};
    printAllSubset(test1);
}