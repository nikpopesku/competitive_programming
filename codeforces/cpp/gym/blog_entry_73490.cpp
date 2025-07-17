#include <iostream>
#include <algorithm>

using namespace std;

string to_binary(int x)
{
    string s;

    while (x > 0)
    {
        s.append(x & 1 ? "1" : "0");
        x = x >> 1;
    }

    ranges::reverse(s);

    return s;
}

int main()
{
    cout << "10 = " << to_binary(10) << endl;

    int x = 20;
    int y = 30;
    cout << "20 = " << to_binary(x) << endl;
    cout << "30 = " << to_binary(y) << endl;

    cout << ((10 ^ 20) ^ 30) << endl;

    cout << "x & y = " << to_binary(x & y) << " x | y = " << to_binary(x | y) << " x ^ y = " << to_binary(x ^ y);
}