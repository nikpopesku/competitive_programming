#include <iostream>
#include <limits>
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

    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            cin >> grid[i][j];
        }
    }

    cout << 1 << "\n";
}
