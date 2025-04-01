#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, L, road1, road2;
    cin >> N >> K >> L;

    vector<vector<int>> roads(N+1);

    for (int i = 0; i < K; ++i) {
        cin >> road1 >> road2;

        roads[road1].push_back(road2);
        roads[road2].push_back(road1);
    }
}