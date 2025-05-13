#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, value;

    std::cin >> t;

    while (t-- > 0)
    {
        cin >> n;
        int mn = 1e9, mx = 1;

        for (int i = 1; i <= n; ++i)
        {
            cin >> value;

            mx = max(mx, value);
            mn = min(mn, value);
        }

        std::cout << mx - mn << "\n";
    }
}
