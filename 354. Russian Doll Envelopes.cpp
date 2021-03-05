#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n==0) return 0; 
        sort(envelopes.begin(), envelopes.end());
        vector<int> lis(n,1); 
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++){ //for each i check from beginning till i if current envelop is bigger in width & height
                if ((envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]))
                    lis[i] = max(lis[i], 1+lis[j]);
            }
        return *max_element(lis.begin(), lis.end()); //return the maxmimum of lis vector
    }
};

int main() {

}