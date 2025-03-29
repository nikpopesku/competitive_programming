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
    set<int> unvisited;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        roads[a].push_back(b);
    }

    for (int city = 1; city <= n; ++city) unvisited.insert(city);

    while (!unvisited.empty()) {
        q.push(*unvisited.begin());

        while (!q.empty()) {
            unvisited.erase(q.front());

            for (auto &road: roads[q.front()]) {
                if (unvisited.find(road) != unvisited.end()) {
                    q.push(road);
                }
            }

            q.pop();
        }


    }


    cout << response.size() << "\n";
    for (int i = 0; i < response.size(); ++i) cout << response[i].first << " " << response[i].second << "\n";
}