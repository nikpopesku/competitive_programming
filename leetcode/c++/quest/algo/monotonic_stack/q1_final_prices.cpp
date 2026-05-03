#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(const vector<int> &prices) {
        const int n = static_cast<int>(prices.size());
        vector final_prices = prices;
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                const int index = st.top();
                st.pop();
                final_prices[index] = final_prices[index] - prices[i];
            }
            st.push(i);
        }

        return final_prices;
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {8, 4, 6, 2, 3}; const auto e: s.finalPrices(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {1, 2, 3, 4, 5}; const auto e: s.finalPrices(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {10, 1, 1, 6}; const auto e: s.finalPrices(nums)) cout << e << ' ';
    cout << '\n';
}
