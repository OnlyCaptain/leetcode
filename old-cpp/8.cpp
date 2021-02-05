#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int myAtoi(string str) {
    char ch;
    int size = str.size();
    int i = 0;
    while (i < size) {  // 去掉空格
        if (str[i] == ' ') {
            i ++;
            continue;
        }
        else break;
    }
    if ((str[i] <= '9' && str[i] >= '0') || str[i] == '-' || str[i] == '+') {
        int base = 1, M = INT_MAX;
        long result = 0;
        if (str[i] == '-') {  // 处理负数
            base = -1;
            M = INT_MIN;
            i ++;
        }
        else if (str[i] == '+') {
            i++;
        }
        for (int j = i; j < size; j ++) {
            ch = str[j];
            if (ch <= '9' && ch >= '0') {
                // if ( (base == 1 && (result > INT_MAX / 10)) || (base == -1 && (result * > INT_MIN * -1 / 10)) ) return M;
                if (result > M  / 10 * base ) return M;
                result *= 10;
                if (result - 1 > base * ( (M - base*(ch - '0') ) - base) ) return M;
                result += ch - '0';
            }
            else return result*base;
        }
        return result*base;
    }
    return 0;
}


int main ()
{
    cout << INT_MIN << endl;
    cout << myAtoi("4193 with words") << endl;
    cout << myAtoi("      -42") << endl;


    cout << myAtoi("words and 987") << endl;
    cout << myAtoi("-91283472332") << endl;

    cout << myAtoi("-2147483648") << endl;

    cout << myAtoi("+1") << endl;

    cout << myAtoi("-000000000000001") << endl;
    cout << myAtoi("+000000000000001") << endl;

    cout << myAtoi("-2147483648") << endl;


}