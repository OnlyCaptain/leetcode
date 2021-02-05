#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int reverse(int x) {
    int base = 1, n_x = 0;
    int result = 0;
    base = (x < 0)?-1:1;
    if (x == INT_MIN) return 0;
    x = (x < 0)?-x:x;
    while ((n_x = x / 10) != 0) {
        result *= 10;
        result += x % 10;
        x = n_x;
    }    
    if (result > INT_MAX / 10) return 0;
    result *= 10;
    result += x % 10;
    // if (result > 2147483647) return 0;
    return (int)result*base;
}


int main()
{
    int a;
    cout << INT_MAX << endl;
    do {
        cin >> a;
        cout << reverse(a) << endl;
    } while (a != 0);
    return 0;
}