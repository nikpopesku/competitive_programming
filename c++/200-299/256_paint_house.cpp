#include <iostream>
#include <vector>

using std::vector, std::min;

class Solution {
public:
    int minCost(const vector<vector<int>>& costs) {
        const size_t n = costs.size();
        vector red(n + 1, 0);
        vector blue(n + 1, 0);
        vector green(n + 1, 0);
        red[1] = costs[0][0];
        blue[1] = costs[0][1];
        green[1] = costs[0][2];

        for (int i = 2; i <= n; i++) {
            red[i] = min(blue[i-1], green[i-1]) + costs[i-1][0];
            blue[i] = min(red[i-1], green[i-1]) + costs[i-1][1];
            green[i] = min(red[i-1], blue[i-1]) + costs[i-1][2];
        }

        return min(red[n], blue[n], green[n]);
    }
};


int main() {
    auto s = Solution();
    std::cout << s.minCost({{17,2,17},{16,16,5},{14,3,19}}) << std::endl;
}
