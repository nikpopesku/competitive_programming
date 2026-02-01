#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> > &edges) {
        return {};
    }
};

int main() {
    Solution s;//[1]
    vector<vector<int> > a = {{1, 0}, {1, 2}, {1, 3}};

    for (auto elem: s.findMinHeightTrees(4, a)) {
        cout << elem << ' ';
    }


    vector<vector<int> > b = {{3,0},{3,1},{3,2},{3,4},{5,4}};//[3,4]
    for (auto elem: s.findMinHeightTrees(6, b)) {
        cout << elem << ' ';
    }
}
