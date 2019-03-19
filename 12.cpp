#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int Roman(char ch) {
    switch(ch) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return -1;
            break;
    }
    return -1;
}

int romanToInt(string s) {
    int j = s.size() -1;
    int result = 0;
    char pre = ' ';
    while (j >= 0) {
        switch(s[j]) {
            case 'I':
                if (pre == 'V' || pre == 'X') result -= Roman(s[j]);
                else result += Roman(s[j]);
                break;
            case 'V':
                result += Roman(s[j]);
                break;
            case 'X':
                if (pre == 'C' || pre == 'L') result -= Roman(s[j]);
                else result += Roman(s[j]);
                break;
            case 'L':
                result += Roman(s[j]);
                break;
            case 'C':
                if (pre == 'M' || pre == 'D') result -= Roman(s[j]);
                else result += Roman(s[j]);
                break;
            case 'D':
                result += Roman(s[j]);
                break;
            case 'M':
                result += Roman(s[j]);
                break;
        }
        pre = s[j];
        j --;
    }
    return result;
}

int main()
{
    cout << romanToInt("I") << endl;
    cout << romanToInt("V") << endl;
    cout << romanToInt("X") << endl;
    cout << romanToInt("M") << endl;
    cout << romanToInt("III") << endl;
    cout << romanToInt("IV") << endl;
    cout << romanToInt("IX") << endl;
    cout << romanToInt("LVIII") << endl;
    cout << romanToInt("MCMXCIV") << endl;
}