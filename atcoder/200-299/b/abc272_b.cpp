#include <iostream>
#include <set>

using namespace std;

int main() {
    unsigned int n, m, value;
    cin >> n >> m;

    set<pair<int, int>> pairs;

    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            pairs.insert({i, j});
        }
    }


    for (int i = 1; i <= m; ++i) {
        set<unsigned int> s;

        for (int j = 0; j < n; ++j) {
            cin >> value;
            s.insert(value);
        }

        for (auto it1 = s.begin(); it1 != s.end(); ++it1) {
            for (auto it2 = ++it1; it2 != s.end(); ++it2) {
                pairs.erase({*it1, *it2});
            }
        }
    }

    cout << (pairs.empty() ? "Yes" : "No") << '\n';
}