#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

class DisjointUnionSet {
public:
    explicit DisjointUnionSet(const int size) : size(size), parent(size) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(const int node) {
        if (node == parent[node]) {
            return node;
        }

        parent[node] = find(parent[node]);

        return parent[node];
    }

    bool unionit(const int a, const int b) {
        int parent_a = find(a);
        int parent_b = find(b);

        if (parent_a == parent_b) {
            return false;
        }

        if (size[parent_a] < size[parent_b]) {
            swap(parent_a, parent_b);
        }

        parent[parent_b] = parent_a;
        size[parent_a] += size[parent_b];

        return true;
    }

private:
    vector<int> size;
    vector<int> parent;
};

class Solution {
public:
    int makeConnected(const int n, const vector<vector<int> > &connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        int counter = 0;

        DisjointUnionSet dsu(n);

        for (auto con: connections) {
            if (dsu.unionit(con[0], con[1])) {
                ++counter;
            }
        }


        return n - 1 - counter;
    }
};

int main() {
    Solution s;

    vector<vector<int> > connections = {{0, 1}, {0, 2}, {1, 2}};
    cout << s.makeConnected(4, connections) << endl; //1

    vector<vector<int> > connections2 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    cout << s.makeConnected(6, connections2) << endl; //2

    vector<vector<int> > connections3 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
    cout << s.makeConnected(6, connections3) << endl; //-1

    return 0;
}
