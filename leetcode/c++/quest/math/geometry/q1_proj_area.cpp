#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int projectionArea(const vector<vector<int> > &grid) {
        const int n = static_cast<int>(grid.size());
        int area = n;

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
