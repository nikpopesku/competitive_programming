#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, start, end;
    ll sx, sy, tx, ty, x, y, r;
    cin >> N;
    cin >> sx >> sy >> tx >> ty;

    vector<tuple<int, int, int>> circle;
    vector<vector<int>> adj_list(N);
    set<ll> unvisited;

    for (int i = 0; i < N; ++i) {
        cin >> x >> y >> r;

        for (size_t j = 0; j < circle.size(); ++j) {
            ll d = sqrt((get<0>(circle[j]) - x) * (get<0>(circle[j]) - x) +
                        (get<1>(circle[j]) - y) * (get<1>(circle[j]) - y));
            if (abs(get<2>(circle[j]) - r) <= d and d <= get<2>(circle[j]) + r) {
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }

        }

        circle.push_back({x, y, r});
        unvisited.insert(i);
        if (sqrt((sx - x) * (sx - x) + (sy - y) * (sy - y)) == r) start = i;
        if (sqrt((tx - x) * (tx - x) + (ty - y) * (ty - y)) == r) end = i;
    }

    queue<int> q;
    q.push(start);
    bool response = false;

    while (!q.empty()) {
        ll elem = q.front();
        q.pop();
        for (auto &e: adj_list[elem]) {
            if (unvisited.count(e) == 1) {
                if (e == end) {
                    response = true;
                    break;
                }

                unvisited.erase(e);
                q.push(e);
            }
        }

        if (response) break;
    }

    cout << (response ? "Yes" : "No") << "\n";
}
