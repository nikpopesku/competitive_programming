#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int> > &connections) {
    }
};

int main() {
    Solution s;

    vector<vector<int> > connections = {{0, 1}, {0, 2}, {1, 2}};
    cout << s.makeConnected(4, connections) << endl; //1

    return 0;
}
