#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, value;
    cin >> N >> M;
    set<int> a;

    for (int i = 0; i < N; ++i) {
        cin >> value;
        a.insert(value);
    }

    set<int> num;

    for (int i = 1; i <= M; ++i) {
        if (a.find(i) != a.end()) continue;

        num.insert(i);
    }

    for (auto it = a.begin(); it != a.end(); ++it) {
        auto it2 = num.begin();

        while (it2 != num.end()) {
            if (gcd(*it, *it2) != 1) {
                it2 = num.erase(it2);
            } else {
                ++it2;
            }
        }
    }

    cout << num.size() << "\n";
    for (auto &elem: num) cout << elem << "\n";
}