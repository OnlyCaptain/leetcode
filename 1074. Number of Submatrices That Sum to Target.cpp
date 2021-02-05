#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int f(vector<int> & v,int t){
        int n = v.size(), sum = 0, ans = 0;
        unordered_map<int,int> map;
        map[0] = 1;  
        for(int i = 0; i < n; i++) {
            sum += v[i];
            if(map.count(sum-t)) 
                ans += map[sum-t];
            map[sum] ++;
        }
        return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& v, int t) {
        if(v.size() == 0)  return 0;
        int row_size = v.size(), col_size = v[0].size(), ans = 0;
        for(int j = 0; j < col_size; j ++) {
            vector<int> a(row_size, 0);
            for(int k = j; k < col_size; k ++) {
                for(int i = 0; i < row_size; i ++)
                    a[i] += v[i][k];
                ans += f(a,t);
            }
        }
        return ans;
    }
};