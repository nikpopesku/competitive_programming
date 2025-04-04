
#include <iostream>
#include <vector>
#include <climits>


using std::cout, std::endl, std::vector, std::max;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        vector dp (prices.size(), vector(2, 0));
        dp[0][1] = std::max(0, prices[1] - prices[0]);

        return 5;
    }
};

int main() {
    auto s = Solution();
    cout << s.maxProfit({3,3,5,0,0,3,1,4}) << endl;
}
