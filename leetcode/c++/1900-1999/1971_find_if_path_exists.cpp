#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int> > &edges, int source, int destination) {
    }
};


int main() {
    auto s = Solution();

    vector<vector<int> > edges = {{0, 1}, {1, 2}, {2, 0}};
    cout << s.validPath(3, edges, 0, 2) << endl;

    vector<vector<int> > edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    cout << s.validPath(6, edges2, 0, 5) << endl;
}
