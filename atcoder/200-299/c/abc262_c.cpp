#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int p = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        if (a[i] == i) {
            ++p;
        }
    }
    long long ans = 1ll * p * (p - 1) / 2;
    for (int i = 0; i < n; ++i) {
        if (a[i] != i) {
            if (a[a[i]] == i and i < a[i]) {
                ++ans;
            }
        }
    }
    cout << ans;

    return 0;
}