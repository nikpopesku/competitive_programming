#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int projectionArea(const vector<vector<int> > &grid) {
        const int n = static_cast<int>(grid.size());

        int zero_height = 0;
        int area = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) ++zero_height;
            }

            area += *max_element(grid[i].begin(), grid[i].end());
        }

        area += n * n - zero_height;

        for (int col = 0; col < n; ++col) {
            const auto max_row_it = max_element(grid.begin(), grid.end(),
                                                [col](const vector<int> &a, const vector<int> &b) {
                                                    return a[col] < b[col];
                                                });
            area += (*max_row_it)[col];
        }

        return area;
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > grid = {{1, 2}, {3, 4}};
    cout << s.projectionArea(grid) << '\n'; //17

    vector<vector<int> > grid2 = {{2}};
    cout << s.projectionArea(grid2) << '\n'; //5

    vector<vector<int> > grid3 = {{1, 0}, {0, 2}};
    cout << s.projectionArea(grid3) << '\n'; //5
}
