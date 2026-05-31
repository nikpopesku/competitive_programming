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
    int response = 0;
    vector<int> sorted_x = x;
    sort(sorted_x.begin(), sorted_x.end());
    sorted_x.erase(unique(sorted_x.begin(), sorted_x.end()), sorted_x.end());

    while (r < n) {
        int sorted_pos_r = lower_bound(sorted_x.begin(), sorted_x.end(), x[r]) - sorted_x.begin();

        while (sorted_x[sorted_pos_r]) {
            ++l;
            int sorted_pos_l = lower_bound(sorted_x.begin(), sorted_x.end(), x[l-1]) - sorted_x.begin();
            sorted_x[sorted_pos_l] = false;
        }

        sorted_x[sorted_pos_r] = true;
        response += r - l + 1;

        r += 1;
    }

    return response;
}
