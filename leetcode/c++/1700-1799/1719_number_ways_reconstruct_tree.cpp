#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int> > &pairs) {
        int n = 1;

        for (auto &p: pairs) {
            n = max(n, max(p[0], p[1]));
        }

        vector<vector<int> > adj(n + 1, vector<int>());
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > pairs = {{1, 2}, {2, 3}};
    cout << s.checkWays(pairs) << '\n';

    vector<vector<int> > pairs2 = {{1, 2}, {2, 3}, {1, 3}};
    cout << s.checkWays(pairs2) << '\n';

    vector<vector<int> > pairs3 = {{1, 2}, {2, 3}, {2, 4}, {1, 5}};
    cout << s.checkWays(pairs3) << '\n';
}
