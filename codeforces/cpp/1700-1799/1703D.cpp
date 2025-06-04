#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool match(map<int, vector<string>> &mp, int j, int k, const string &st) {
    for (auto &s1: mp[j]) {
        for (auto &s2: mp[k]) {
            if (s1 + s2 == st) {
                return true;
            }
        }
    }

    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<string> vc(n);
    map<int, vector<string>> mp;

    for (int i = 0; i < n; ++i) {
        cin >> vc[i];
        mp[static_cast<int>(vc[i].size())].push_back(vc[i]);
    }
    string response;

    for (int i = 0; i < n; ++i) {
        if (vc[i].size() == 1) {
            response += "0";
            continue;
        }

        bool found = false;

        for (int j = 1; j <= vc[i].size() - 1; ++j) {
            int k = static_cast<int>(vc[i].size()) - j;
            if (match(mp, j, k, vc[i])) {
                found = true;
                break;
            }
        }

        response += (found ? "1" : "0");
    }

    cout << response << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}