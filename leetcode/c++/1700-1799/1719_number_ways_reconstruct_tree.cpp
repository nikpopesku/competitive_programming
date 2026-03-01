#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {

    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    cout << s.checkWays(tickets) << '\n';
}
