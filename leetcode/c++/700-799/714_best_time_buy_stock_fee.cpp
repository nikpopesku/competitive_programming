
#include <iostream>
#include <vector>
#include <climits>


using std::cout, std::endl, std::vector, std::max;

class Solution {
public:
    int maxProfit(const vector<int>& prices, int fee) {
        long long sold = 0;
        long long held = 0;

        for (auto &p:prices) {
            const long long pre_sold = sold;
            sold = held + p - fee;
            held = max(held, pre_sold - p);
        }

        return sold;
    }
};

int main() {
    auto s = Solution();
    cout << s.maxProfit({1,3,7,5,10,3}, 2) << endl;
}
