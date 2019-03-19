#include <iostream>
#include <climits>

using namespace std;

bool isPalindrome(int x) {
    long bx = (x > 0)?x:-x;
    long result = 0;
    while ((bx / 10) != 0) {
        result *= 10;
        result += bx % 10;
        bx /= 10;
    }
    result *= 10;
    result += bx % 10;
    // cout << result << endl;
    if ((int)result != x) return false;
    return true;
}

int main()
{
    cout << isPalindrome(-121) << endl;
    cout << isPalindrome(121) << endl;
    cout << isPalindrome(10) << endl;
    return 0;
}