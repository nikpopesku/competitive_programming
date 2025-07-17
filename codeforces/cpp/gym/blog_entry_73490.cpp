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
    cout << "13 = " << to_binary(13) << endl; // 1101

    int x = 53;
    int y = 28;
    cout << "53 = " << to_binary(x) << endl; // 1101
    cout << "28 = " << to_binary(y) << endl; // 1101

    cout << "x & y = " << to_binary(x & y) << " x | y = " << to_binary(x | y) << " x ^ y = " << to_binary(x ^ y);
}