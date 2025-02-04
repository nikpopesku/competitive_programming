#include <iostream>
#include <vector>
#include <map>

using namespace std;

int ffind(map<int, vector<int>> mp, int x, int xx) {
    int left = 0, right = mp[x].size() - 1;

    while (left <= right) {
        int m = left + (right - left) / 2;

        if (mp[x][m] == xx) {
            return m;
        } else if (mp[x][m] < xx) {
            left = m + 1;
        } else {
            right = m - 1;
        }
    }

    return mp[x][left] <= xx ? mp[x][left] : mp[x][right];
}

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

        cout << ffind(mp, x, r) - ffind(mp, x, r) + 1 << endl;
    }

}