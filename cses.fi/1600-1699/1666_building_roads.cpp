#include<iostream>
#include <numeric>
#include <vector>

using namespace std;

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(const int size): size(size + 1), parent(size + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int index) const {
        while (index != parent[index]) {
            index = parent[index];
        }

        return index;
    }

    bool unite(const int node_a, const int node_b) {
        int parent_a = find(node_a);
        int parent_b = find(node_b);

        if (parent_a == parent_b) return false;

        if (size[parent_a] < size[parent_b]) swap(parent_a, parent_b);

        parent[parent_b] = parent_a;
        size[parent_a] += size[parent_b];

        return true;
    }
private:
    vector<int> size;
    vector<int> parent;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, u, v;
    cin >> n >> m;
    vector adj(n, vector<int>());
    DisjointSetUnion dsu(n);

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dsu.unite(u, v);
    }
}
