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

        for (auto &dest: adj | views::values) {
            sort(dest.rbegin(), dest.rend());
        }

        vector<string> result;

        dfs(adj, result, "JFK");
        ranges::reverse(result);

        return result;
    }

private:
    void dfs(unordered_map<string, vector<string> > &adj, vector<string> &result, const string &u) {
        while (adj[u].empty()) {
            auto e = adj[u].back();
            adj[u].pop_back();
            dfs(adj, result, e);
        }
 result.push_back(u);
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
