#include <iostream>
#include <vector>

using namespace std;

#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C;

    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N+1);

    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C;

        adj[a].emplace_back(C, B);
    }


    cout << -1 << '\n';
}
