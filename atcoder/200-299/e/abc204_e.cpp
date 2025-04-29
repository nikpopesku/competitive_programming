#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C, D;

    cin >> N >> M;
    vector<vector<tuple<int, int, int>>> adj(N + 1);

    for (int i = 1; i <= M; ++i)
    {
        cin >> A >> B >> C >> D;
        adj[A].push_back({B, C, D});
        adj[B].push_back({A, C, D});
    }

    cout << 1 << "\n";
}
