#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k, value;
    cin >> n >> m;
    vector<stack<int>> cylinder(m);
    unordered_map<int, int> pool{};

    for (int i = 0; i < m; ++i) {
        cin >> k;

        for (int j = 0; j < k; ++j) {
            cin >> value;
            cylinder[i].push(value);
        }
    }

    unordered_set<int> to_parse;
    for (int i = 0; i < m; ++i) to_parse.insert(i);
    bool condition = true;

    while (condition) {
        condition = false;
        pool = {};

        for (auto it = to_parse.begin(); it != to_parse.end();) {
            if (!cylinder[*it].empty()) {
                value = cylinder[*it].top();

                if (!pool.contains(value)) {
                    pool[value] = *it;
                } else {
                    condition = true;
                    cylinder[*it].pop();
                    cylinder[pool[value]].pop();
                    pool.erase(value);
                }

                ++it;
            } else {
                it = to_parse.erase(it);
            }
        }
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