#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void solve() {
    int n, k, max_k = 0;
    string value;
    cin >> n;
    vector<string> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> k;
        max_k = max(max_k, k);
        for (int j = 0; j < k; ++j) {
            cin >> value;
            a[i] += value;
        }
    }

    ranges::sort(a.begin(), a.end());
    vector<char> response(max_k);

    int i = 0;
    while (i < max_k) {
        for (int j = 0; j < n; ++j) {
            if (a[j].size() > i) {
                for (; i < a[j].size(); ++i) {
                    response[i] = a[j][i];
                }
            }
        }
    }


    for (const auto &e: response) {
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}
