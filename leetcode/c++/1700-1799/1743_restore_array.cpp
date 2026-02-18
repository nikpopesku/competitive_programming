#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> restoreArray(const vector<vector<int> > &adjacentPairs) {
        unordered_map<int, vector<int> > adj;

        for (const auto &p: adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        const int n = static_cast<int>(adjacentPairs.size()) + 1;

        vector<int> response(n);
        for (auto &[fst, snd]: adj) {
            if (snd.size() == 1) {
                response[0] = fst;
                break;
            }
        }

        int current = adj[response[0]][0];
        int counter = 0;
        while (++counter < n) {
            response[counter] = current;

            current = adj[current][0] != response[counter - 1] ? adj[current][0] : adj[current][1];
        }


        return response;
    }
};

int main() {
    Solution s;

    vector<vector<int> > descriptions = {{2, 1}, {3, 4}, {3, 2}};
    for (auto &elem: s.restoreArray(descriptions)) {
        cout << elem << ' ';
    }

    return 0;
}
