#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, start = -1, end = -1;
    ll sx, sy, tx, ty, x, y, r;
    cin >> N;
    cin >> sx >> sy >> tx >> ty;

    vector<tuple<int, int, int>> circle;
    vector<vector<int>> adj_list(N);
    vector<bool> visited(N);

    for (int i = 0; i < N; ++i) {
        cin >> x >> y >> r;

        circle.push_back({x, y, r});
        visited[i] = false;
        if (sqrt((sx - x) * (sx - x) + (sy - y) * (sy - y)) == r) start = i;
        if (sqrt((tx - x) * (tx - x) + (ty - y) * (ty - y)) == r) end = i;
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ll x1 = get<0>(circle[i]), y1 = get<1>(circle[i]), r1 = get<2>(circle[i]);
            ll x2 = get<0>(circle[j]), y2 = get<1>(circle[j]), r2 = get<2>(circle[j]);
            ll dist_sq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            ll sum_r_sq = (r1 + r2) * (r1 + r2);
            ll diff_r_sq = (r1 - r2) * (r1 - r2);

            if (diff_r_sq <= dist_sq && dist_sq <= sum_r_sq) {
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }
        }
    }


    if (start == -1 || end == -1) {
        cout << "No\n";
        return 0;
    }

    queue<int> q;
    q.push(start);
    visited[start] = true;
    bool response = false;

    while (!q.empty()) {
        ll curr = q.front();
        q.pop();

        if (curr == end) {
            response = true;
            break;
        }

        for (auto &neighbor: adj_list[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << (response ? "Yes" : "No") << "\n";
}
