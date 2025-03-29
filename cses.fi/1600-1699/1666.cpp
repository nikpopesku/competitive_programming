#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;
    queue<int> q;
    vector<vector<int>> roads(n + 1);
    vector<pair<int, int>> response;
    vector<int> u(n);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }

    iota(u.begin(), u.end(), 1);
    set<int> unvisited(u.begin(), u.end());
    int previous = 0;

    while (!unvisited.empty()) {
        q.push(*unvisited.begin());
        if (previous > 0) response.push_back({previous, *unvisited.begin()});

        while (!q.empty()) {
            unvisited.erase(q.front());
            previous = q.front();
            for (auto &road: roads[q.front()]) if (unvisited.count(road)) q.push(road);
            q.pop();
        }
    }


    cout << response.size() << "\n";
    for (auto &elem: response) cout << elem.first << " " << elem.second << "\n";
}