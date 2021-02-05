#include <iostream>
#include <vector>
#include <climits>


using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == 0 || divisor == 0) return 0;
    int quotient = 0, base = 1;
    base = (divisor > 0)?base:-base;
    base = (dividend > 0)?base:-base;
    if (base == -1) {
        divisor = -divisor;
    }
    if (dividend < 0) {
        while (dividend <= divisor) {
            dividend -= divisor;
            if (quotient == INT_MAX) return INT_MAX;
            quotient ++;
        }
    }
    else {
        while (dividend >= divisor) {
            dividend -= divisor;
            if (quotient == INT_MAX) return INT_MAX;
            quotient ++;
        }
    }
    return (base > 0)?quotient:-quotient;
}

int main()
{
    cout << INT_MIN << endl;
    cout << divide(10, 3) << endl;
    cout << divide(7, -3) << endl;
    cout << divide(0, 1) << endl;
    cout << divide(1,1) << endl;
    cout << divide(-1, 1) << endl;
    cout << divide(2147483647, 1) << endl;
}