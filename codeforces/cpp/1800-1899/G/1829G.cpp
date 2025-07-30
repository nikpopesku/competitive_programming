#include <iostream>
#include <vector>

using namespace std;

#define ll long long

constexpr ll N = 2023;

pair<ll,ll> find(const vector<vector<ll>>& v, const ll n)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (v[i][j] == n) return {i, j};
        }
    }

    return {};
}

void solve(const vector<vector<ll>>& v)
{
    ll n;
    cin >> n;
    auto [start_row, start_col] = find(v, n);
    ll len = 1;
    ll response = 0;

    for (ll i = start_row; i >= 0; --i)
    {
        for (ll j = start_col; j < start_col + len; ++j)
        {
            response += v[i][j] * v[i][j];
        }
    }


    cout << response << "\n";
}

int main()
{
    vector v(N, vector<ll>(N, 0));
    ll start = N / 2;
    ll len = 1;
    ll index = 1;

    for (int i = 0; i < N; ++i)
    {
        int len_counter = 0;
        for (int j = 0; j < N; ++j)
        {
            if (len_counter < len && j >= start)
            {
                v[i][j] = index++;
                ++len_counter;
            }
        }
        ++len;
        --start;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve(v);
    }
}
