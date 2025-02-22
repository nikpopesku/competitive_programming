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

    bool condition = true;

    while (condition) {
        condition = false;

        for (size_t i = 0; i < m; ++i) {
            if (!cylinder[i].empty()) {
                value = cylinder[i].top();

                if (!pool.contains(value)) {
                    pool[value] = i;
                } else {
                    pool.erase(value);
                    condition = true;
                }

                cylinder[i].pop();
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