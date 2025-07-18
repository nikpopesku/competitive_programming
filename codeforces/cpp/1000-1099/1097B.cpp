#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    bool response = false;

    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i <= std::pow(2, n - 1); ++i)
    {
        int value = i;
        int j = 0;
        int sum = 0;

        while (j <= n - 1)
        {
            sum += (value & (1 << j) ? 1 : -1) * v[j];
            ++j;
        }

        if (sum % 360 == 0)
        {
            response = true;
            break;
        }
    }

    cout << (response ? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
