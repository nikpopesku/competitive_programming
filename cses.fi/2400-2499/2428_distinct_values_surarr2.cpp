#include<bits/stdc++.h>

using namespace std;

constexpr int VALUES = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> x(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    int l = 0, r = 0;
    long long response = 0;
    vector<int> sorted_x = x;
    ranges::sort(sorted_x);
    sorted_x.erase(ranges::unique(sorted_x).begin(), sorted_x.end());
    const int sz = static_cast<int>(sorted_x.size());
    vector val(sz, false);

    while (r < n) {
        const int sorted_pos_r = static_cast<int>(ranges::lower_bound(sorted_x, x[r]) - sorted_x.begin());

        while (val[sorted_pos_r] || r - l + 1 > k) {
            ++l;
            const int sorted_pos_l = static_cast<int>(ranges::lower_bound(sorted_x, x[l - 1]) - sorted_x.begin());
            val[sorted_pos_l] = false;
        }

        val[sorted_pos_r] = true;
        response = response + r - l + 1;

        r += 1;
    }

    cout << response << '\n';
}
