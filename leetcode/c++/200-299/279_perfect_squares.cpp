#include <cmath>
#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int numSquares(const int n) {
        std::vector dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;

        std::vector<int> squares{};

        for (int i = 1; i <= std::sqrt(n); i++) {
            squares.push_back(i * i);
        }

        for (int i = 2; i <= n; i++) {
            for (const auto sq: squares) {
                if (sq > i) {
                    break;
                }

                dp[i] = std::min(dp[i], dp[i - sq] + 1);
            }
        }

        return dp[n];
    }
};


int main() {
    auto s = Solution();
    std::cout << s.numSquares(4) << std::endl;
}
