#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    int maximalRectangle(const vector<vector<char> > &matrix) {
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        int max_rectangle = 0;
        vector<int> current_height(m, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j < m && matrix[i][j] == 1) {
                    ++current_height[j];
                } else if (j < m) {
                    current_height[j] = 0;
                }
            }
        }


        return max_rectangle;
    }
};

int main() {
    auto s = Solution();

    vector<vector<char> > matrix = {
        {"1", "0", "1", "0", "0"}, {"1", "0", "1", "1", "1"}, {"1", "1", "1", "1", "1"}, {"1", "0", "0", "1", "0"}
    };

    for (auto row: s.maximalRectangle(matrix)) {
        for (auto cell: row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }
}
