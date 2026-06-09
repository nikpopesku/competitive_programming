#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        const int n = static_cast<int>(grid.size());
        const int m = static_cast<int>(grid[0].size());
        vector<int> column_width(n, 0);


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = abs(grid[i][j]);
                int width = val != 0 ? 0 : 1;

                while (val) {
                    ++width;
                    val /= 10;
                }

                if (grid[i][j] < 0) ++width;

                column_width[j] = max(column_width[j], width);
            }


        }

        return column_width;
    }
};

int main() {
    auto s = Solution();

    cout << boolalpha << s.consecutiveSetBits(6) << endl; //true
    cout << boolalpha << s.consecutiveSetBits(5) << endl; //false
    cout << boolalpha << s.consecutiveSetBits(30) << endl; //false
}
