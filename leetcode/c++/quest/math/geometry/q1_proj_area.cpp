#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int projectionArea(const vector<vector<int> > &grid) {
        const int n = static_cast<int>(grid.size());
        const int m = static_cast<int>(grid[0].size());

        int zero_height = 0;
        int area = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) ++zero_height;
            }

            area += *max_element(grid[i].begin(), grid[i].end());
        }

        area += n * n - zero_height;

        return area;
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > grid = {{1, 2}, {3, 4}};
    cout << s.projectionArea(grid) << '\n'; //17

    vector<vector<int> > grid2 = {{2}};
    cout << s.projectionArea(grid2) << '\n'; //5
}
