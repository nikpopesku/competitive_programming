#include <iostream>

using ll = long long;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    if (r1 == r2 && c1 == c2)
    {
        cout << "0\n";

        return 0;
    }

    if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || abs(r1 - r2) + abs(c1 - c2) <= 3)
    {
        cout << "1\n";

        return 0;
    }

    if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || abs(r1 - r2) + abs(c1 - c2) <= 3)
    {
        cout << "1\n";

        return 0;
    }

    cout << "3\n";
}
