#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
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
    using T = pair<pair<int, int>, int>;
    priority_queue<T, vector<T>, greater<>> pq;
    unordered_map<char, vector<pair<int, int>>> mp;
    int start_x = 0, start_y = 0;
    int end_x = 0, end_y = 0;

    for (int i = 0; i < H; ++i)
    {
        cin >> grid[i];

        for (int j = 0; j < W; ++j)
        {
            if (grid[i][j] == 'S')
            {
                start_x = i;
                start_y = j;
            }

            if (grid[i][j] == 'G')
            {
                end_x = i;
                end_y = j;
            }

            if (grid[i][j] >= 'a' and grid[i][j] <= 'z')
            {
                mp[grid[i][j]].emplace_back(i, j);
            }
        }
    }


    const vector direction_x = {1, -1, 0, 0};
    const vector direction_y = {0, 0, 1, -1};
    pq.push({{start_x, start_y}, 0});

    while (!pq.empty())
    {
        const auto [coord, distance] = pq.top();
        pq.pop();
        const auto& [x, y] = coord;

        if (distance > dist[x][y]) continue;

        if (grid[x][y] >= 'a' and grid[x][y] <= 'z')
        {
            bool found = false;
            for (auto& [new_x, new_y] : mp[grid[x][y]])
            {
                if ((new_x != x or new_y != y) and distance + 1 < dist[new_x][new_y])
                {
                    pq.push({{new_x, new_y}, distance + 1});
                    dist[new_x][new_y] = distance + 1;
                    found = true;
                    break;
                }
            }

            if (found) continue;
        }


        for (int i = 0; i < 4; ++i)
        {
            int new_x = x + direction_x[i];
            int new_y = y + direction_y[i];

            if (new_x < 0 or new_x >= H or new_y < 0 or new_y >= W) continue;

            if (grid[new_x][new_y] == '#' or grid[new_x][new_y] == 'S' or distance + 1 >= dist[new_x][new_y]) continue;

            pq.push({{new_x, new_y}, distance + 1});
            dist[new_x][new_y] = distance + 1;
        }
    }

    cout << (dist[end_x][end_y] == INF ? -1 : dist[end_x][end_y]) << "\n";
}
