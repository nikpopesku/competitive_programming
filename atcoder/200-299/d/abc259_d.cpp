#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    ll sx, sy, tx, ty, x, y, r;
    cin >> N;
    cin >> sx >> sy >> tx >> ty;

    vector<tuple<int, int, int>> circle(N);

    for (int i = 0; i < N; ++i) {
        cin >> x >> y >> r;

        circle.push_back({x, y, r});
    }

    cout << 1 << "\n";
}