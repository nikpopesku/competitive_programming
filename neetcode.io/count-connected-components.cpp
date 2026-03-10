#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int> > &edges) {
    }
};


int main() {
    auto s = Solution();

    vector<vector<int> > edges = {{0, 1}, {1, 2}, {3, 4}};
    cout << boolalpha << s.countComponents(5, edges) << '\n'; //1

    vector<vector<int> > edges2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    cout << boolalpha << s.countComponents(5, edges2) << '\n'; //2
}
