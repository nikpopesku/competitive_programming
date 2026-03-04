#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int> > &graph) {
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > graph = {{1, 2, 3}, {0}, {0}, {0}};
    cout << s.shortestPathLength(graph) << endl; //4
}
