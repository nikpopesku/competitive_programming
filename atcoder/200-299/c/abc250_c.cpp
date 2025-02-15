#include <iostream>
#include <map>

using namespace std;

#define ll long long

int main() {
    int n, q, value, sw;
    cin >> n >> q;

    map<int, int> mp;
    for (int i = 1; i <= n; ++i) mp[i] = i;

    for (int i = 1; i <= q; ++i) {
        cin >> value;
        if (mp[value] + 1 <= n) {
            sw = mp[value] + 1;
        } else {
            sw = mp[value] - 1;
        }

        int temp = mp[sw];
        mp[sw] = mp[value];
        mp[value] = temp;
    }

    for (int i = 1; i < n; ++i) cout << mp[i] << ' ';
    cout << mp[n - 1] << '\n';
}