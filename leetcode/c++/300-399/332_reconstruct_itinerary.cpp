#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(const vector<vector<string> > &tickets) {
        unordered_map<string, vector<string> > adj;

        for (auto &e: tickets) {
            adj[e[0]].push_back(e[1]);
        }

        // Sort in reverse for efficient pop_back
        for (auto &dests: adj | views::values) {
            sort(dests.begin(), dests.end());
        }

        vector<string> result;

        // Hierholzer's algorithm (post-order DFS)
        auto dfs = [&](auto &&self, const string &u) -> void {
            while (!adj[u].empty()) {
                string v = adj[u].back();
                adj[u].pop_back();  // remove edge
                self(self, v);
            }
            result.push_back(u);  // post-order
        };

        dfs(dfs, "JFK");
        ranges::reverse(result);
        return result;
    }
};

int main() {
    auto s = Solution();

    vector<vector<string> > tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

    for (auto &e: s.findItinerary(tickets)) {
        cout << e << ' '; //["JFK","MUC","LHR","SFO","SJC"]
    }

    cout << '\n';

    vector<vector<string> > tickets2 = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};

    for (auto &e: s.findItinerary(tickets2)) {
        cout << e << ' '; //["JFK","ATL","JFK","SFO","ATL","SFO"]
    }
}
