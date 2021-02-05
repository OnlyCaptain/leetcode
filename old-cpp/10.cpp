#include <iostream>
#include <string>
#include <stack>
// #include <stack>
using namespace std;

bool isMatch(string const & s, string const & p, int i, int j) {
    return s[i] == p[j] || p[j] == '.';
}

// solution
bool isMatch(string s, string p) {
    int i = s.length() - 1;
    int j = p.length() - 1;
    // std::stack backtrack;
    std::stack<int> backtrack;
    while (i >= 0 || j >= 0) {
        // test simple match
        if (j >= 0 && i >= 0 && (s[i] == p[j] || p[j] == '.')) {
            --i;
            --j;
        } // 从后往前匹配如果相等只需直接向前减一。

        else if (j > 0 && p[j] == '*') {  // 从后往前，计算 * 匹配多少个字符
            // see how many p[j-1]'s can be matched
            while (i >= 0 && isMatch(s, p, i, j - 1)) {
            // if need to backtrack:
            // restore state as if p[j-1] and p[j] didn't exist
                backtrack.push(i);
                backtrack.push(j - 2);
                --i;
            }
            j -= 2;
        } // 

        // matching failed, can we backtrack?
        else if (!backtrack.empty()) {
            j = backtrack.top(); backtrack.pop();
            i = backtrack.top(); backtrack.pop();
        }
        // pattern does not match
        else {
            return false;
        }
    }
    return true;
}


int main()
{
    cout << isMatch("aa", "a") << endl;
    cout << isMatch("ab", ".*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
    cout << isMatch("mississippi", "mis*is*p*.") << endl;
    cout << isMatch("ab", ".*c") << endl;
    cout << isMatch("aaaaa", "a*a") << endl;
    return 0;

}
// bool isMatch(string s, string p) {
//     int s_size = s.size();
//     int p_size = p.size();
//     int s_i = 0, p_i = 0;

//     char pre;
//     int len=1;
//     pre = p[0];
//     if (p[0] == s[0] || p[0] == '.') p_i == 0;
//     if (p[0] == '*') return false;
//     if (p[0] != s[0] && p[1] == '*') {
//         pre = '*';
//         p_i = 2;
//     }
//     if (p[0] != s[0] && p[0] != '.' && p[1] != '*') return false;
//     if (p[0] == '.') p_i = 0;
//     // if (p[0] == '.') pre = s[0];

//     while (s_i != s_size) {
//         if (p_i >= p_size) break;
//         switch(p[p_i]) {
//             case '.':
//                 pre = '.'; 
//                 s_i ++;
//                 p_i ++;
//                 break;
            
//             case '*':
//                 if (s[s_i] == pre || pre == '.') {
//                     s_i ++;
//                     break;
//                 }  
//                 else if (s[s_i] != pre && pre != '.') {
//                     if (p_i >= p_size) return false;
//                     else {
//                         pre = '*';
//                         p_i ++;
//                     } 
//                 }
//                 break;
            
//             default:
//                 if (s[s_i] != p[p_i]) {
//                     if (p_i + 1 >= p_size) return false;
//                     if (p[p_i+1] == '*') {
//                         pre = '*';
//                         p_i += 2;
//                     }
//                     else return false;
//                 } 
//                 else {
//                     pre = p[p_i];
//                     s_i ++;
//                     p_i ++;
//                 }
//                 // return false;
//                 break;
//         }
//     }
//     if (p[p_i] == '*') p_i ++;
//     if (p_i != p_size) return false;
//     if (s_i == s_size)
//         return true;
//     else return false;
// }
// }