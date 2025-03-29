#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> roads(n + 1);
    vector<pair<int, int>> response;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        roads[a].push_back(b);
    }

    cout << response.size() << "\n";
    for (int i = 0; i < response.size(); ++i) cout << response[i].first << " " << response[i].second << "\n";
}