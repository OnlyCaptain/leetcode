#include <iostream>
#include <vector>


using namespace std;

int countArea(int len, int h1, int h2) {
    return len*(h1>h2?h2:h1);
}

int maxArea(vector<int>& height) {
    int maxArea = 0, tmpArea = 0;
    int i = 0, j = height.size() - 1;
    while (i != j) {
        tmpArea = countArea(j-i, height[i], height[j]);
        if (tmpArea > maxArea) {
            maxArea = tmpArea;
        }
        if (height[i] > height[j]) 
            j --;
        else i ++;
    }
    return maxArea;
}


int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
}