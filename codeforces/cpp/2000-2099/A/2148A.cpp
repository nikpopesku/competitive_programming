#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (auto i = 0; i < t; i++)
    {
        int x, n;
        cin >> x >> n;
        cout << (n % 2 == 0 ? 0 : x) << "\n";
    }

    return 0;
}
