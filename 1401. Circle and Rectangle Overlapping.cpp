#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    float distance(int x1, int y1, int x2, int y2) {
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int left = min(x1, x2), right = max(x1, x2), top = max(y1, y2), bottom = min(y1, y2);
        if (left <= x_center && x_center <= right && bottom <= y_center && y_center <= top) {
            cout << " 0 " << endl;
            return true; // 圆点
        }
        if (left <= x_center && x_center <= right && (abs(y_center-top) <= radius || abs(y_center-bottom) <= radius)) {
            cout << " 1 " << endl;
            return true;
        }
        if (bottom <= y_center && y_center <= top && (abs(x_center-left) <= radius || abs(x_center-right) <= radius)) {
            cout << " 2 " << endl;
            return true;
        }
            
        float min_distance = min({distance(x_center, y_center, x1, y1), distance(x_center, y_center, x1, y2),
                         distance(x_center, y_center, x2, y1),distance(x_center, y_center, x2, y2)});
        cout << min_distance << endl;
        cout << distance(0,19, 22, 8) << endl;
        if (min_distance <= (float)radius) return true;
        return false;
    }
};

int main() {
    Solution a;
    cout << a.checkOverlap(27, 0, 19, 22, 8, 28, 18) << endl;
}