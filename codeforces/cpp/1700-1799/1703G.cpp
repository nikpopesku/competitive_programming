#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> a(n);

    int response = 0;


    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (sum / 2 > k)
        {
            response += a[i] - k;
            sum -= a[i];
        }
        else
        {
            response += a[i] / 2;
            sum -= a[i];
            sum /= 2;
        }
    }

    cout << response << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
