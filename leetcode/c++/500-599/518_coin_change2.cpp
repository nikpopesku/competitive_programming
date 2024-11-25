#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int change(const int amount, const std::vector<int>& coins) {
        std::vector dp (coins.size()+1, std::vector<unsigned long long> (amount+1, 0));

        for (int i = 0; i <= coins.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = coins.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i+1][j];
                } else {
                    dp[i][j] = dp[i+1][j] + dp[i][j - coins[i]];
                }
            }
        }

        return dp[0][amount] <= INT_MAX ? dp[0][amount] : -1;
    }
};


class Solution2 {
public:
    int change(const int amount, const std::vector<int>& coins) {
        std::vector<unsigned long long> dp (amount+1, 0);
        dp[0] = 1;

        for (int i = coins.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i] <= j) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }

        return dp[amount];
    }
};

int main() {
    auto s = Solution2();
    std::cout << s.change(5, {1,2,5}) << std::endl;
}
