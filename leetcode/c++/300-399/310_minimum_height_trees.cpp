#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(const int n, const vector<vector<int> > &edges) {
        if (n == 1) {
            return {0};
        }

        unordered_map<int, unordered_set<int> > mp;

        for (auto e: edges) {
            mp[e[0]].insert(e[1]);
            mp[e[1]].insert(e[0]);
        }

        while (mp.size() > 2) {
            vector<pair<int, int>> del = {};
            for (const auto &e: mp) {
                if (e.second.size() <= 1) {
                    del.emplace_back(e.first, *e.second.begin());
                }
            }
            for (auto d: del) {
                mp.erase(d.first);
                mp[d.second].erase(d.first);
            }
        }

        vector<int> response;

        for (const auto key: mp | views::keys) {
            response.push_back(key);
        }

        return response;
    }
};

int main() {
    Solution s; //{1}
    vector<vector<int> > a = {{1, 0}, {1, 2}, {1, 3}};

    for (const auto elem: s.findMinHeightTrees(4, a)) {
        cout << elem << ' ';
    }
    cout << '\n';


    vector<vector<int> > b = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}}; //{3,4}
    for (const auto elem: s.findMinHeightTrees(6, b)) {
        cout << elem << ' ';
    }
    cout << '\n';


    vector<vector<int> > c = {{0,1},{0,2},{0,3},{3,4},{4,5}};
    for (const auto elem: s.findMinHeightTrees(6, c)) {
        cout << elem << ' ';
    }
}
