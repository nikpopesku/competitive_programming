#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>

using namespace std;

class DisjointUnionSet {
public:
    DisjointUnionSet(int size): size(size, 1), parent(size) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(const int node) {
        if (node == parent[node]) {
            return node;
        }

        parent[node] = find(node);

        return parent[node];
    }

    bool unionit(int a, int b) {
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
    vector<int> parent;
    vector<int> size;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mst;

        sort(edges.begin(), edges.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        DisjointUnionSet dsu(n);
        int min_weight = 0;

        for (auto &e: edges) {
            if (dsu.unionit(e[0], e[1])) {
                mst.push_back(e);
                min_weight += e[2];
            }

            if (mst.size() == n - 1) {
                break;
            }
        }
    }
};

int main() {
    auto s = Solution();

    vector<vector<string> > edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};

    for (auto &e: s.findCriticalAndPseudoCriticalEdges(5, edges)) {
        cout << e << ' '; //[[0,1],[2,3,4,5]]
    }

    // cout << '\n';
}
