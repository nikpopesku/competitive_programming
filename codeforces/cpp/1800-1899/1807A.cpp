#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int a;
    int b;
    int c;
    int t;
    vector<string> sign;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;
        if (a + b == c) {
            sign.push_back("+");
        } else {
            sign.push_back("-");
        }
    }

    for (auto& it : sign) {
        cout << it << endl;
    }

    return 0;
}