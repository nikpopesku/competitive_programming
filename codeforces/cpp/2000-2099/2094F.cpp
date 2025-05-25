#include <iostream>
#include <vector>
#include <numeric> // Only for completeness, not strictly used in this specific logic

// Helper function to print the grid (optional, can be in solve)
void print_grid(const std::vector<std::vector<int>>& grid, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << grid[i][j] << (j == m - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
}

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> grid(n, std::vector<int>(m));

    if (m % k != 0)
    {
        // Case 1: Row-major fill
        // Works because m % k != 0 ensures vertical adjacency.
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                grid[i][j] = ((i * m + j) % k) + 1;
            }
        }
    }
    else if (n % k != 0)
    {
        // Case 2: m % k == 0 AND n % k != 0. Column-major fill.
        // Works because n % k != 0 ensures horizontal adjacency.
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                grid[i][j] = ((j * n + i) % k) + 1;
            }
        }
    }
    else
    {
        // Case 3: m % k == 0 AND n % k == 0. Diagonal fill.
        // Works because both n and m being multiples of k ensures frequency,
        // and (i+j) pattern ensures adjacency.
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                grid[i][j] = ((i + j) % k) + 1;
            }
        }
    }

    print_grid(grid, n, m);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
