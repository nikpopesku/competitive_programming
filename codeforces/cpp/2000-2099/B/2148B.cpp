#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
        }

        cout << n + m << "\n";
    }

    return 0;
}
