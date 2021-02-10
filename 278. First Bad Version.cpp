#include <iostream>
using namespace std;

bool isBadVersion(int i) {
    return false;
}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int left = 1, right = n, medium = (left+right)/2;
        while (medium != left && medium != right) {
            if (isBadVersion(medium)) {
                right = medium;
            }
            else left = medium;
            medium = (long)(left+right)/2;
        }
        
        return isBadVersion(left)?left:right;
    }
};

int main() {

}