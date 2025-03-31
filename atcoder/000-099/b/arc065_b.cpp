#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, L, city1, city2;
    cin >> N >> K >> L;
    vector<vector<int>> roads(K);
    vector<vector<int>> railways(L);
    vector<int> response(N, 1);

    for (int i = 0; i < K; ++i) {
        cin >> city1 >> city2;

        roads[city1].push_back(city2);
        roads[city2].push_back(city1);
    }

    for (int i = 0; i < L; ++i) {
        cin >> city1 >> city2;

        railways[city1].push_back(city2);
        railways[city2].push_back(city1);
    }

    for (size_t i = 0; i < response.size(); ++i) cout << response[i] << (i != response.size() - 1 ? " " : "\n");
}
