#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(n);
        int current_side = 0;
        int current_time = 0;
        int response = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i] >> b[i];
            --a[i];

            int min_val = current_side != b[i] ? 1 : 0;
            if (a[i] >= current_time + min_val)
            {
                const int val = a[i] - current_time - min_val;
                response += val / 2 * 2;
                current_time = a[i] - min_val;
            }

            if (a[i] > current_time)
            {
                ++response;
            }

            current_time = a[i];
            current_side = b[i];
        }

        cout << response << "\n";
    }

    return 0;
}
