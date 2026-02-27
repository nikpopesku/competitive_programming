#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(const vector<vector<string> > &tickets) {
        unordered_map<string, vector<string> > adj;
        unordered_map<string, bool> visited;

        for (auto &e: tickets) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            visited[e[0]] = false;
            visited[e[1]] = false;
        }

        vector<string> stack;

        stack.emplace_back("JFK");
        visited["JFK"] = true;
        vector<string> response;

        while (!stack.empty()) {
            string elem = stack[0];
            response.push_back(elem);

            vector<string> neighbours {};
            for (auto &nei: adj[elem]) {
                if (!visited[nei]) {
                    neighbours.push_back(nei);
                }

                ranges::sort(neighbours);
            }
            stack.clear();
            if (!neighbours.empty()) {
                stack.push_back(neighbours[0]);
                visited[neighbours[0]] = true;
            }
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    // vector<vector<string> > tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    //
    // for (auto &e: s.findItinerary(tickets)) {
    //     cout << e << ' ';
    // }
    //
    // cout << '\n';

    vector<vector<string> > tickets2 = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};

    for (auto &e: s.findItinerary(tickets2)) {
        cout << e << ' '; //["JFK","ATL","JFK","SFO","ATL","SFO"]
    }
}
