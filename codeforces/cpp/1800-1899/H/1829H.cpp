#include <iostream>
#include <vector>

using namespace std;

#define ll long long

constexpr ll N = 2023;

pair<ll,ll> find(const vector<vector<ll>>& v, const ll n)
{
    const ll dd = n * n;

    ll left = 0;
    ll right = N - 1;
    ll i = 0;

    while (left < right)
    {
        const ll mid = left + (right - left) / 2;

        if (v[mid][0] <= dd && ((mid < N - 1 && v[mid + 1][0] > dd) || mid == N - 1))
        {
            i = mid;
            break;
        }

        if (v[mid][0] > dd)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (i == 0) i = left;

    for (int j = 0; j < N; ++j)
    {
        if (v[i][j] == dd) return {i, j};
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
        for (ll j = max(start_col, 0LL); j < min(start_col + len, N); ++j)
        {
            response += v[i][j];
        }
        ++len;
        --start_col;
    }


    cout << response << "\n";
}

int main()
{
    vector v(N, vector<ll>(N, 0));
    ll len = 1;
    ll index = 1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            v[i][j] = index * index;
            ++index;
        }
        ++len;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve(v);
    }
}
