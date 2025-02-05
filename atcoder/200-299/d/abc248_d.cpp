#include <iostream>
#include <map>

using namespace std;

int ffind(map<int, map<int, int>> mp, int x, int xx) {
    if (xx == 0) return 0;

    auto yyy = mp[x];
    int left = 0, right = mp[x].size() - 1;

    while (left < right) {
        int m = left + (right - left + 1) / 2;

        if (mp[x].count(m) and mp[x][m] == xx) {
            return m;
        } else if (mp[x].count(m) and mp[x][m] > xx) {
            right = m - 1;
        } else {
            left = m;
        }
    }

    return left;
}

int main() {
    int n, q, value;
    cin >> n;
    map<int, map<int, int>> mp;

    for (int i = 1; i <= n; ++i) {
        cin >> value;
        if (mp[value].empty()) mp[value].emplace(0, 0);
        mp[value].emplace(mp[value].size(), i);
    }

    cin >> q;
    int l, r, x;

    for (int i = 0; i < q; ++i) {
        cin >> l >> r >> x;

        if (mp[x].empty()) {
            cout << "0\n";
            continue;
        }

        int pos_r = ffind(mp, x, r), pos_l = ffind(mp, x, l - 1);

        cout << pos_r - pos_l << endl;
    }

}