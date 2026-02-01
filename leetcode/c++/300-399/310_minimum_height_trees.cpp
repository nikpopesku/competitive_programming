#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> > &edges) {
        unordered_map<int, vector<int>> mp;

        for (auto e : edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
    }
};

int main() {
    Solution s; //[1]
    vector<vector<int> > a = {{1, 0}, {1, 2}, {1, 3}};

    for (auto elem: s.findMinHeightTrees(4, a)) {
        cout << elem << ' ';
    }


    vector<vector<int> > b = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}}; //[3,4]
    for (auto elem: s.findMinHeightTrees(6, b)) {
        cout << elem << ' ';
    }
}
