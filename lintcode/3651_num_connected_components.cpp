#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: the number of vertices
     * @param edges: the edges of undirected graph
     * @return: the number of connected components
     */
    int countComponents(int n, vector<vector<int>> &edges) {
        // write your code here
    }
};


int main() {
    auto s = Solution();

    const vector<vector<int> > edges = [[0,1], [0,2]];
    cout << s.countComponents(edges) << endl; //1

    const vector<vector<int> > edges2 = [[0,1], [1,2], [2, 3], [4, 5]];
    cout << s.countComponents(edges2) << endl; //2
}
