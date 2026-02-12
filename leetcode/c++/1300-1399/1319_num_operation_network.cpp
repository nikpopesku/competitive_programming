#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class DisjointUnionSet {
public:
    DisjointUnionSet(int size): size(size), parent(size) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (node != parent[node]) {
            node = parent[node];
        }

        return node;
    }
private:
    vector<int> size;
    vector<int> parent;
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int> > &connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
    }
};

int main() {
    Solution s;

    vector<vector<int> > connections = {{0, 1}, {0, 2}, {1, 2}};
    cout << s.makeConnected(4, connections) << endl; //1

    return 0;
}
