#include <iostream>
#include <vector>

using namespace std;

#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr); // Not strictly necessary

    int N;
    int M; // Use int for N, M as per constraints (<= 2*10^5)
    cin >> N >> M;
    int A, B, C, D;
    vector<vector<tuple<int, int , int>>> adj(N+1);

    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C >> D;
        adj[A].emplace_back(B, C, D);
        adj[B].emplace_back(A, C, D);
    }
}
