#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string> > &tickets) {
        vector<vector<string>> adj(300, vector<string>());

        for (auto &e: tickets) {
            adj[e[0]].push_back(e[1]);
        }
    }
};

int main() {
    auto s = Solution();

    vector<vector<string> > tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

    for (auto &e: s.findItinerary(tickets)) {
        cout << e << ' ';
    }
}
