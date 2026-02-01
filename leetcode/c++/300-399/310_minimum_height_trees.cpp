#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        return {};
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a = {{1,0},{1,2},{1,3}};

    for (auto elem : s.findMinHeightTrees(3, a)) {
        cout << elem << ' ';
    }
}
