#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(const vector<vector<string> > &tickets) {
        unordered_map<string, vector<string> > adj;
        set<pair<string, string> > visited;

        for (auto &e: tickets) {
            adj[e[0]].push_back(e[1]);
        }

        vector<string> stack;

        stack.emplace_back("JFK");
        vector<string> response;

        while (!stack.empty()) {
            string elem = stack[0];
            response.push_back(elem);

            vector<string> neighbours{};
            for (auto &nei: adj[elem]) {
                if (!visited.contains(pair{elem, nei})) {
                    neighbours.push_back(nei);
                }

                ranges::sort(neighbours);
            }
            stack.clear();
            if (!neighbours.empty()) {
                stack.push_back(neighbours[0]);
                visited.insert(pair{elem, neighbours[0]});
            }
        }

        return response;
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
