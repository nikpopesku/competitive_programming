#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
    }
};

int main() {
    Solution s;

    vector<vector<int>> a = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << s.validTree(5, a) << endl; //1

    vector<vector<int>> b = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << s.validTree(b, 5) << endl; //0

    return 0;
}
