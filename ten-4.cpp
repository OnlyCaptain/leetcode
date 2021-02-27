#include <random>
#include <string>
#include <iostream>
using namespace std;
char choose(int i) {
    i %= 10;
    if (i == 0) return 'a';
    if (i == 1 || i == 2) return 'b';
    if (i == 3 || i == 4 || i == 5) return 'c';
    return 'd';
}
string selectAd() {
    string ans;
    int first = (rand()%10), second = (rand()%10);
    while (first == second) {
        first = (rand()%10);
        second = (rand()%10);
    }
    ans += choose(first);
    ans += choose(second);
    return ans;
}

int main() {
    // 假设有4个广告abcd, 每次从中选出两个不重复的广告，如ab, bc, cd, 要求最终abcd出现的概率为1:2:3:4
    // 哈夫曼
    int n = 5;
    while (n--) {
        cout << selectAd() << endl;
    }
}