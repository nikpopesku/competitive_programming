#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int catMouseGame(vector<vector<int> > &graph) {
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    cout << s.catMouseGame(graph) << endl; //0
}
