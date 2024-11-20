
#include <iostream>
#include <vector>
#include <climits>


using std::cout, std::endl, std::vector, std::max;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int sold = INT_MIN;
        int held = INT_MIN;
        int reset = 0;

        for (auto &p: prices) {
            int pre_sold = sold;
            sold = held + p;
            held = max(held, reset - p);
            reset = max(reset, pre_sold);
        }

        return max(sold, reset);
    }
};

int main() {
    auto s = Solution();
    cout << s.maxProfit({1,2,3,0,2}) << endl;
}
