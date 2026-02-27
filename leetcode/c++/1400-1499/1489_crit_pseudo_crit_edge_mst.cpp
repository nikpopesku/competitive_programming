#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>

using namespace std;

class DisjointUnionSet {
public:
    DisjointUnionSet(int size) : size(size, 1), parent(size) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(const int node) {
        if (node == parent[node]) {
            return node;
        }

        parent[node] = find(parent[node]);

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
    vector<vector<int> > findCriticalAndPseudoCriticalEdges(int n, vector<vector<int> > &edges) {
        for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        int min_weight = kruskal(n, edges, -1, -1);
        vector<int> critical;
        vector<int> pseudo_critical;

        for (auto &e: edges) {
            const int weight = kruskal(n, edges, e[3], -1);

            if (weight > min_weight) {
                critical.push_back(e[3]);
            } else {
                int forced_weight = kruskal(n, edges, -1, e[3]);

                if (forced_weight == min_weight) {
                    pseudo_critical.push_back(e[3]);
                }
            }
        }

        return {critical, pseudo_critical};
    }

private:
    int kruskal(const int n, const vector<vector<int> > &edges, const int exclude_idx, const int force_idx) {
        DisjointUnionSet dsu(n);
        int min_weight = 0;
        int counter = 0;

        for (auto &e: edges) {
            if (e[3] == force_idx) {
                ++counter;
                min_weight += e[2];
                dsu.unionit(e[0], e[1]);
            }
        }

        for (auto &e: edges) {
            if (e[3] == exclude_idx) continue;
            if (dsu.unionit(e[0], e[1])) {
                min_weight += e[2];
            }

            if (counter == n - 1) {
                break;
            }
        }

        return min_weight;
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};

    for (auto &e: s.findCriticalAndPseudoCriticalEdges(5, edges)) {
        for (auto &j: e) {
            cout << j << ' '; //[[0,1],[2,3,4,5]]
        }
        cout << '\n';
    }

    // cout << '\n';
}
