#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector forest(n, vector<int>(n));

    for (int i = 0 ; i < n; ++i) {
        for (int j = 0; j < n; ++i) {
            cin >> forest[i][j];
        }
    }
}