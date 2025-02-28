#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll max_answer = 0;
vector<pair<int, int>> pairs{};
int used[16];
int a[16][16];
int n;

ll calc() {
    if (pairs.size() == n) {
        ll answer = 0;
        for (auto &elem: pairs) answer ^= a[elem.first][elem.second];

        return answer;
    }
    int l = 0;
    while (l < 2 * n) {
        if (!used[l]) {
            used[l] = true;
            break;
        }

        ++l;
    }

    for (int r = 0; r < 2 * n; ++r) {
        if (!used[r]) {
            used[r] = true;
            pairs.emplace_back(l, r);
            max_answer = max(max_answer, calc());
            pairs.pop_back();
            used[r] = false;
        }
    }


    used[l] = false;

    return max_answer;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;


    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = i + 1; j < 2 * n; ++j) {
            cin >> a[i][j];
        }
    }

    calc();

    cout << max_answer << "\n";
}