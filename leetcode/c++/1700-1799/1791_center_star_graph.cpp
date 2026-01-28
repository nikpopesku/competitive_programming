#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

    }
};


int main() {
    auto s = Solution();

    const vector<vector<int> > edges = {{1,2},{2,3},{4,2}};
    cout << s.findCenter(edges) << endl; //2

    const vector<vector<int> > edges2 = {{1,2},{5,1},{1,3},{1,4}};
    cout << s.findCenter(edges2) << endl; //1
}
