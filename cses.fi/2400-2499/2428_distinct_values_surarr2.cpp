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
    bool val[VALUES] = {false};

    while (r < n) {
        while (val[x[r]]) {
            ++l;
            val[x[l-1]] = false;
        }

        val[x[r]] = true;
        response += r - l + 1;

        r += 1;
    }

    return response;
}
