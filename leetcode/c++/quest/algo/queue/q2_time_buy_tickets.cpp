#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        queue<pair<int, int> > q;
        int time = 0;
        for (int i = 0; i < static_cast<int>(tickets.size()); ++i) q.emplace(i, tickets[i]);

        while (true) {
            ++time;
            auto [fst, snd] = q.front();
            if (q.front().second > 1) {
                q.emplace(fst, snd - 1);
            }
            q.pop();
            if (fst == k && snd == 1) break;
        }

        return time;
    }
};

int main() {
    auto s = Solution();
    vector<int> tickets = {2, 3, 2};
    cout << s.timeRequiredToBuy(tickets, 2) << '\n'; //6

    vector<int> tickets2 = {5, 1, 1, 1};
    cout << s.timeRequiredToBuy(tickets2, 0) << '\n'; //8
}
