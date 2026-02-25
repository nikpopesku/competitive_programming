#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {

    }
};
int main() {
    auto s = Solution();

    vector<vector<int>> &queries = {{1, 4}, {2, 5}, {3, 6}};
    for (auto e: s.areConnected(6, 2, queries)) {
        cout << boolalpha << e << ' ';
    }
}
