#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, L, val1, val2;
    cin >> N >> K >> L;

    vector<vector<int>> roads(N+1);

    for (int i = 0; i < K; ++i) {
        cin >> val1 >> val2;

        roads[val1].push_back(val2);
        roads[val2].push_back(val1);
    }

    vector<vector<int>> railways(N+1);

    for (int i = 0; i < K; ++i) {
        cin >> val1 >> val2;

        railways[val1].push_back(val2);
        railways[val2].push_back(val1);
    }
}