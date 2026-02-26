#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string> > &tickets) {
    }
};

int main() {
    auto s = Solution();

    vector<vector<string> > tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

    for (auto &e: s.findItinerary(tickets)) {
        cout << e << ' ';
    }
}
