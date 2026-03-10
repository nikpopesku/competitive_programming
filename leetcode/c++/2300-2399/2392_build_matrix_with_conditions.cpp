#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > buildMatrix(int k, vector<vector<int> > &rowConditions, vector<vector<int> > &colConditions) {
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > rowConditions = {{1, 2}, {3, 2}};
    vector<vector<int> > colConditions = {{2, 1}, {3, 2}};
    for (auto &e: s.buildMatrix(3, rowConditions, colConditions)) {
        cout << e{0} << ' ' << e{1} << '\n';
    }

    cout << '\n';

    vector<vector<int> > rowConditions2 = {{1, 2}, {2, 3}, {3, 1}, {2, 3}};
    vector<vector<int> > colConditions2 = {{2, 1}};
    for (auto &e: s.buildMatrix(3, rowConditions2, colConditions2)) {
        cout << e{0} << ' ' << e{1} << '\n';
    }
}
