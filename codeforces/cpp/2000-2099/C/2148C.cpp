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

            if (a[i] - 1 >= current_time + 2)
            {
                response += a[i] - 1 - current_time;
                a[i] -= current_time - 1;
            }

            if (a[i] > 0)
            {
                if (a[i] % 2 == 0)
                {
                    response += current_side != b[i] ? 2 : 1;
                }
                else if (current_side != b[i])
                {
                    ++response;
                }
            }

            current_time = a[i] - 1;
            current_side = b[i];
        }

        cout << n + m << "\n";
    }

    return 0;
}
