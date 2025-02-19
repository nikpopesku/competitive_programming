#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, value;
    cin >> n >> m;
    vector<vector<int>> vc(m);

    for (int i = 0; i < m; ++i) {
        cin >> k;

        for (int j = 0; j < k; ++j) {
            cin >> value;
            vc[i][j] = value;
        }
    }
}