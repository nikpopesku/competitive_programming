#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, value;
    cin >> n >> m;
    vector<stack<int>> cylinder(m);
    unordered_map<int, int> pool;

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
        vector<int> to_add;
        for (int i = 0; i < to_parse.size(); ++i) {
            if (!cylinder[i].empty()) {
                value = cylinder[i].top();

                if (!pool.contains(value)) {
                    pool[value] = i;
                } else {
                    to_add.push_back(i);
                    to_add.push_back(pool[value]);
                    pool.erase(value);
                }
            }
        }

        to_parse = to_add;
    }
}