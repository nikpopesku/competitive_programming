#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> restoreArray(const vector<vector<int> > &adjacentPairs) {
        unordered_map<int, vector<int> > degree;

        for (const auto &p: adjacentPairs) {
            degree[p[0]].push_back(p[1]);
            degree[p[1]].push_back(p[0]);
        }

        const int n = static_cast<int>(adjacentPairs.size()) + 1;

        vector<int> response(n);
        for (auto &[fst, snd]: degree) {
            if (snd.size() == 1) {
                response[0] = fst;
                break;
            }
        }
    }
};

int main() {
    Solution s;

    vector<vector<int> > descriptions = {{2, 1}, {3, 4}, {3, 2}};
    s.restoreArray(descriptions);

    return 0;
}
