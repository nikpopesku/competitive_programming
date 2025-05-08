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
    vector<string> grid(H);
    vector dist(H, vector(W, INF));
    priority_queue<pair<pair<int, int>, int>> pq;
    for (int i = 0; i < H; ++i) cin >> grid[i];

    int response = 0;
    const vector direction_x = {1, -1, 0, 0};
    const vector direction_y = {0, 0, 1, -1};
    pq.push({{0, 0}, 0});

    while (!pq.empty())
    {
        ++response;
        const auto [coord, distance] = pq.top();
        pq.pop();
        const auto& [x, y] = coord;

        if (grid[x][y] == 'G') break;

        if (distance > dist[x][y]) continue;

        for (int i = 0; i < 4; ++i)
        {
            int new_x = x + direction_x[i];
            int new_y = y + direction_y[i];

            if (new_x < 0 or new_x >= H or new_y < 0 or new_y >= W) continue;

            if (grid[new_x][new_y] != '#' and grid[new_x][new_y] != 'S' and response < dist[new_x][new_y])
            {
                pq.push({{new_x, new_y}, response});
                dist[new_x][new_y] = response;
            }
        }
    }

    cout << response << "\n";
}
