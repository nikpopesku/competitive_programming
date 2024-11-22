#include <iostream>
#include <vector>

using std::vector, std::min;

class Solution {
public:
    int minCostII(const vector<vector<int>>& costs) {
        const size_t m = costs.size();
        const size_t n = costs[0].size();
        vector dp (m+1, vector(n, 0));

        for (size_t i = 1; i <= m; i++) {
            for (size_t j = 0; j < n; j++) {
                vector<int> others {};
                others.insert(others.end(), dp[i-1].begin(), dp[i-1].begin() + j);
                others.insert(others.end(), dp[i-1].begin() + j + 1, dp[i-1].end());
                dp[i][j] = minValue(others) + costs[i-1][j];
            }
        }

        return minValue(dp[m]);
    }
private:
    int minValue(vector<int>& dp) {
        int response = dp[0];
        for (const auto &val: dp) {
            if (val < response) response = val;
        }

        return response;
    }
};


int main() {
    auto s = Solution();
    std::cout << s.minCostII({{17,2,17},{16,16,5},{14,3,19}}) << std::endl;
}
