
#include <iostream>
#include <vector>
#include <climits>


using std::cout, std::endl, std::vector, std::max;

class Solution {
public:
    int maxProfit(const vector<int>& prices, int fee) {
        long long sold = INT_MIN;
        long long held = INT_MIN;

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
    cout << s.maxProfit({1,2,3,0,2}, 2) << endl;
}
