#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, value;
    cin >> n;
    map<int, vector<int>> mp;

    for (int i = 1; i <= n; ++i) {
        cin >> value;
        mp[value].push_back(i);
    }

    cin >> q;
    int l, r, x;

    for (int i = 0; i < q; ++i) {
        cin >> l >> r >> x;

        if (mp[x].empty()) {
            cout << "0\n";
            continue;
        }

        cout << upper_bound(mp[x].begin(), mp[x].end(), r) - lower_bound(mp[x].begin(), mp[x].end(), l) << endl;
    }

}