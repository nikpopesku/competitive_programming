#include<bits/stdc++.h>

using namespace std;

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
    vector val(sz, 0);
    int current_total = 0;

    while (r < n) {
        const int sorted_pos_r = static_cast<int>(ranges::lower_bound(sorted_x, x[r]) - sorted_x.begin());

        ++val[sorted_pos_r];
        if (val[sorted_pos_r] == 1) {
            ++current_total;
        }

        while (current_total > k) {
            const int sorted_pos_l = static_cast<int>(ranges::lower_bound(sorted_x, x[l]) - sorted_x.begin());
            --val[sorted_pos_l];
            if (val[sorted_pos_l] == 0) {
                --current_total;
            }
            ++l;
        }

        response = response + r - l + 1;

        r += 1;
    }

    cout << response << '\n';
}
