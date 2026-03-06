#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    vector<vector<int> > validArrangement(vector<vector<int> > &pairs) {
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > pairs = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    for (auto &e: s.validArrangement(pairs)) {
        cout << e[0] << ' ' << e[1] << '\n';
    }
}
