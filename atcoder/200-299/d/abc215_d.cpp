#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> a(N);

    set<int> factor;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];

        for (int j = 2; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                factor.insert(j);
                a[i] /= j;
            }
        }

        if (a[i] > 1) factor.insert(a[i]);
    }

    vector<bool> response(M + 1, true);

    for (auto &elem: factor) {
        int value = elem;
        while (value <= M) {
            if (response[value]) response[value] = false;
            value += elem;
        }
    }

    int counter = 0;
    for (int i = 1; i <= M; ++i) if (response[i]) ++counter;
    cout << counter << "\n";
    for (int i = 1; i <= M; ++i) if (response[i]) cout << i << "\n";
}