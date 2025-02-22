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
    unordered_map<int, int> pool {};

    for (int i = 0; i < m; ++i) {
        cin >> k;

        for (int j = 0; j < k; ++j) {
            cin >> value;
            cylinder[i].push(value);
        }
    }

    vector<int> to_parse(m);

    iota(to_parse.begin(), to_parse.end(), 0);

    while (!to_parse.empty()) {
        vector<int> to_add{};
        for (size_t i = 0; i < to_parse.size(); ++i) {
            if (!cylinder[i].empty()) {
                value = cylinder[i].top();

                if (!pool.contains(value)) {
                    pool[value] = i;
                } else {
                    to_add.push_back(i);
                    to_add.push_back(pool[value]);
                    pool.erase(value);
                }

                cylinder[i].pop();
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