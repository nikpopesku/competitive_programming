#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int> > &queries) {
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > queries = {{1, 4}, {2, 5}, {3, 6}};
    for (auto e: s.areConnected(6, 2, queries)) {
        cout << boolalpha << e << ' '; //{false,false,true}
    }

    cout << '\n';

    vector<vector<int> > queries2 = {{4, 5}, {3, 4}, {3, 2}, {2, 6}, {1, 3}};
    for (auto e: s.areConnected(6, 0, queries2)) {
        cout << boolalpha << e << ' '; //{true,true,true,true,true}
    }

    cout << '\n';

    vector<vector<int> > queries3 = {{4, 5}, {4, 5}, {3, 2}, {2, 3}, {3, 4}};
    for (auto e: s.areConnected(5, 1, queries3)) {
        cout << boolalpha << e << ' '; //{true,true,true,true,true}
    }
}
