#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 100'007;


bool ok(const int n, vector<int>& binary_decimals)
{
    if (n == 1)
    {
        return true;
    }

    bool response = false;

    for (const int k: binary_decimals)
    {
        if (n % k == 0)
        {
            response |= ok(n / k, binary_decimals);
        }

        if (response) break;
    }

    return response;
}

void solve(vector<int>& binary_decimals)
{
    int n;
    cin >> n;

    cout << (ok(n, binary_decimals) ? "YES" :  "NO") << "\n";
}

int main()
{

    vector<int> binary_decimals;

    int t;
    cin >> t;

    int i = 2;

    while (i <= MAX)
    {
        int current = i;
        bool flag = true;

        while (current)
        {
            if (current % 10 > 1)
            {
                flag = false;
                break;
            }

            current /= 10;
        }

        if (flag)
        {
            binary_decimals.push_back(i);
        }

        i++;
    }

    while (t--)
    {
        solve(binary_decimals);
    }
}
