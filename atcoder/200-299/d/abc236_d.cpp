#include<bits/stdc++.h>

using namespace std;

#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll value;
    unordered_map<int, ll> mp{};
    int n;
    cin >> n;

    for (int i = 0; i < 2 * n; ++i) {
        for (int j = i + 1; j < 2 * n; ++j) {
            cin >> value;
            mp[i * 10 + j] = value;
        }
    }
}