#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll max_answer = 0;

ll calc(unordered_map<string, ll> &mp, set<int> s, ll answer) {
    auto it1 = s.begin();
    while (it1 != s.end()) {
        int val1 = *it1;
        it1 = s.erase(it1);
        auto it2 = it1;
        while (it2 != s.end()) {
            answer ^= mp[to_string(*it1) + "_" + to_string(*it2)];
            int val2 = *it2;
            it2 = s.erase(it2);
            answer = calc(mp, s, answer);
            s.insert(val2);
        }
        s.insert(val1);
    }

    if (answer > max_answer) max_answer = answer;

    return answer;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll answer = 0;
    unordered_map<string, ll> mp{};

    int n;
    cin >> n;


    for (int i = 0; i < 2 * n; ++i) {
        for (int j = i + 1; j < 2 * n; ++j) {
            cin >> mp[to_string(i) + "_" + to_string(j)];
        }
    }

    std::vector<int> vec(2 * n);
    std::iota(vec.begin(), vec.end(), 0);
    set<int> s;
    s.insert(vec.begin(), vec.end());
    calc(mp, s, answer);

    cout << max_answer << "\n";
}