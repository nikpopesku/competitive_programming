#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > pairs = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    for (auto &e: s.buildMatrix(pairs)) {
        cout << e[0] << ' ' << e[1] << '\n';
    }

    cout << '\n';

    vector<vector<int> > pairs2 = {{1, 3}, {3, 2}, {2, 1}};
    for (auto &e: s.validArrangement(pairs2)) {
        cout << e[0] << ' ' << e[1] << '\n';
    }
}
