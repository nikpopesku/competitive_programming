#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q, value, sw;
    cin >> n >> q;

    map<int, int> mp;
    for (int i = 1; i <= n; ++i) mp[i] = i;

    while (q--) {
        cin >> value;
        if (mp[value] + 1 <= n) {
            sw = mp[value] + 1;
        } else {
            sw = mp[value] - 1;
        }
        swap(mp[mp[sw]], mp[value]);
    }

    for (int i = 1; i <= n; ++i) cout << mp[i] << ' ';
}