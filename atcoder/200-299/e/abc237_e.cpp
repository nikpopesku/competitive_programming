#include<iostream>
#include<vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;

    cin >> N >> M;
    vector<int> spaces(N + 1);
    vector<vector<pair<int, int>>> adj(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        cin >> spaces[i];
    }

    int space1, space2;

    for (int j = 0; j < M; ++j)
    {
        cin >> space1 >> space2;
        int cost, cost_inverse;

        if (spaces[space1] >= spaces[space2])
        {
            cost = spaces[space1] - spaces[space2];
            cost_inverse = -2 * cost;
        }
        else
        {
            cost_inverse = spaces[space2] - spaces[space1];
            cost = -2 * cost_inverse;
        }

        adj[space1].push_back({cost, space2});
        adj[space2].push_back({cost_inverse, space1});
    }

    cout << 1 << '\n';
}
