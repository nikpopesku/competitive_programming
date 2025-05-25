#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector vc(n, vector<int>(m));

    if (m % k != 0)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                vc[i][j] = (i * m + j) % k + 1;
            }
        }
    }
    else if (n % k != 0)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                vc[i][j] = (j * n + i) % k + 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                vc[i][j] = (j + i) % k + 1;
            }
        }
    }


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << vc[i][j] << " ";
        }

        cout << "\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
