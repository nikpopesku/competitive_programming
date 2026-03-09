#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int> > &edges) {
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << s.validTree(1, 2) << '\n'; //10
}
