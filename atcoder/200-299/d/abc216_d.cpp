#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k, value;
    cin >> n >> m;
    vector<vector<int>> cylinder(m);
    unordered_map<int, int> pool;

    for (int i = 0; i < m; ++i) {
        cin >> k;

        cylinder[i].resize(k);

        for (int j = 0; j < k; ++j) {
            cin >> cylinder[i][j];
        }
    }

    vector<int> to_parse(m);
    iota(to_parse.begin(), to_parse.end(), 0);

    while (!to_parse.empty()) {
        vector<int> to_add{};
        for (int j : to_parse) {
            if (!cylinder[j].empty()) {
                value = cylinder[j].back();

                if (!pool.contains(value)) {
                    pool[value] = j;
                } else {
                    to_add.push_back(j);
                    to_add.push_back(pool[value]);
                    cylinder[j].pop_back();
                    cylinder[pool[value]].pop_back();
                    pool.erase(value);
                }
            }
        }

        to_parse = to_add;
    }

    string response = "No";

    if (pool.empty()) {
        response = "Yes";

        for (int i = 0; i < m; ++i) {
            if (!cylinder[i].empty()) {
                response = "No";
                break;
            }
        }
    }

    cout << response << "\n";
}