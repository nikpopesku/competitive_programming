#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q, value;
    cin >> n >> q;

    vector<int> a(n + 1), pos(n + 1);
    iota(a.begin(), a.end(), 0);
    iota(pos.begin(), pos.end(), 0);

    while (q--) {
        cin >> value;
        int i = pos[value], j = i + 1;
        if (j == n + 1) {
            j = i - 1;
        }
        swap(a[i], a[j]);
        swap(pos[a[i]], pos[a[j]]);
    }

    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
}