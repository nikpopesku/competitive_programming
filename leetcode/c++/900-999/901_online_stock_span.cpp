#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;


class StockSpanner {
public:
    StockSpanner() {
    }

    int next(const int price) {
        prices.push_back(price);
        int index = counter;


        while (!st.empty() && prices[st.top()] < price) {
            index = st.top();
            st.pop();
        }

        st.push(counter++);

        return counter - index;
    }

private:
    vector<int> prices;
    stack<int> st;
    int counter = 0;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    auto s = Solution();

    for (vector<int> nums1 = {1, 2, 1}; const auto e: s.nextLargerNodes(nums1))
        cout << e << ' ';
    cout << '\n';

    for (vector<int> nums1 = {1, 2, 3, 4, 3}; const auto e: s.nextLargerNodes(nums1))
        cout << e << ' ';
    cout << '\n';
}
