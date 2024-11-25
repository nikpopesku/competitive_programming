#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int mincostTickets(const vector<int>& days, const vector<int>& costs) {
        if (days.empty()) return 0;
        if (dp.find(days[0]) != dp.end()) return dp[days[0]];


        vector a(days.begin() + 1, days.end());
        int one = costs[0] + mincostTickets(a, costs);
        int seven = costs[1];
        int thirty = costs[2];


        vector<int> b {};

        for (vector<int>::size_type i = 0; i < days.size(); i++) {
            if (days[i] < days[0] + 7) {
                continue;
            }

            b.push_back(days[i]);
        }

        if (!b.empty()) {
            seven += mincostTickets(b, costs);
        }


        vector<int> c {};

        for (vector<int>::size_type i = 0; i < days.size(); i++) {
            if (days[i] < days[0] + 30) {
                continue;
            }

            c.push_back(days[i]);
        }

        if (!c.empty()) {
            thirty += mincostTickets(c, costs);
        }

        dp[days[0]] = min(min(one, seven), thirty);

        return dp[days[0]];
    }
private:
    unordered_map<int, int> dp {};
};

int main() {
    auto s = Solution();
    cout << s.mincostTickets({1,2,3,4,5,6,7,8,9,10,30,31}, {2,7,15}) << endl;
    cout << s.mincostTickets({1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,24,25,27,28,29,30,31,34,37,38,39,41,43,44,45,47,48,49,54,57,60,62,63,66,69,70,72,74,76,78,80,81,82,83,84,85,88,89,91,93,94,97,99}, {9,38,134}) << endl;
}