#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findCenter(const vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }

        return edges[0][1];
    }
};


int main() {
    auto s = Solution();

    const vector<vector<int> > edges = {{1,2},{2,3},{4,2}};
    cout << s.findCenter(edges) << endl; //2

    const vector<vector<int> > edges2 = {{1,2},{5,1},{1,3},{1,4}};
    cout << s.findCenter(edges2) << endl; //1
}
