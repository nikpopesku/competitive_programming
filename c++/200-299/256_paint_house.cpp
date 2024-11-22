#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minCost(const vector<vector<int>>& costs) {
        vector<int> red(costs.size() + 1, 0);
        vector<int> blue(costs.size() + 1, 0);
        vector<int> green(costs.size() + 1, 0);
        red[1] = costs[0][0];
        blue[1] = costs[0][1];
        green[1] = costs[0][2];

        return 4;
    }
};


int main() {
    auto s = Solution();
    std::cout << s.minCost({{17,2,17},{16,16,5},{14,3,19}}) << std::endl;
}
