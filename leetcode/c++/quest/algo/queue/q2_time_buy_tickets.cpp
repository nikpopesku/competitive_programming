#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        int time = 0;
        const int n = static_cast<int>(tickets.size());

        for (int i = 0; i < k; ++i) time += min(tickets[i], tickets[k]);
        for (int i = k + 1; i < n; ++i) time += min(tickets[i], tickets[k] - 1);

        return time + tickets[k];
    }
};

int main() {
    auto s = Solution();
    vector<int> tickets = {2, 3, 2};
    cout << s.timeRequiredToBuy(tickets, 2) << '\n'; //6

    vector<int> tickets2 = {5, 1, 1, 1};
    cout << s.timeRequiredToBuy(tickets2, 0) << '\n'; //8
}
