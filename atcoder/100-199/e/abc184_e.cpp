#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

int INF = numeric_limits<int>::max() / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector grid(H, vector<string>(W));
    vector dist(H, vector(W, INF));
    priority_queue<pair<pair<int, int>, int>> pq;


    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == "S")
            {
                dist[i][j] = 0;
                pq.push({{i, j}, 0});
            }
        }
    }

    int response = 0;

    while (!pq.empty())
    {
        auto & [coord, distance] = pq.pop();
        pq.top();
        auto & [x, y] = coord;

        if (grid[x][y] == 'G') break;

        if (distance > dist[x][y]) continue;

        ++response;
    }

    cout << response << "\n";
}
