#include <iostream>
#include <vector>

using namespace std;

bool is_bigger(const vector<int>& a, const int& k, const int& i, const int& n)
{
    int local_sum = 0;
    for (int j = i; j < n; ++j)
    {
        local_sum += a[j] / 2;

        if (local_sum > k) break;
    }

    return local_sum > k;
}


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    int response = 0;


    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (is_bigger(a, k, i, n))
        {
            response += a[i] - k;
        }
        else
        {
            response += a[i] / 2;
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
