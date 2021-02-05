#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    map<int, string> Pam;
    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 88 ,9 ,10};
    Pam[1] = "first";
    Pam[2] = "second";
    Pam[3] = "third";
    string a = "hello world";
    a += "!!!!";
    while (N--) {
        cout << a << endl;
        // cout << "Hello world!" << endl;
        cout << "Hello world!" << endl;
    }
}