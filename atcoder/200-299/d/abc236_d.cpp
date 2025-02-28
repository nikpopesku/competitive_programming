#include<bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    ll max_answer = 0;
    unordered_map<string, ll> mp{};

    int n;
    cin >> n;


    for (int i = 0; i < 2 * n; ++i) {
        for (int j = i + 1; j < 2 * n; ++j) {
            cin >> mp[to_string(i) + "_" + to_string(j)];
        }
    }

    std::vector<int> v(2 * n);
    std::iota(v.begin(), v.end(), 0);


    do {
        ll answer = 0;
        for (int i = 0; i <= n; i += 2)
            answer ^= mp[to_string(min(v[i], v[i + 1])) + "_" + to_string(max(v[i], v[i + 1]))];
        if (answer > max_answer) max_answer = answer;
    } while (next_permutation(v.begin(), v.end()));

    cout << max_answer << "\n";
}