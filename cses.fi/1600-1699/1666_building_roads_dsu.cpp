#include<iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(const int size) : size(size + 1, 1), parent(size + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    [[nodiscard]] int find(int index) {
        if (index == parent[index]) {
            return index;
        }

        return parent[index] = find(parent[index]);
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, u, v;
    cin >> n >> m;
    DisjointSetUnion dsu(n);

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        dsu.unite(u, v);
    }

    set<int> visited;

    for (int i = 1; i <= n; ++i) {
        if (int parent = dsu.find(i); !visited.contains(parent)) {
            visited.insert(parent);
        }
    }

    cout << visited.size() - 1 << '\n';
    for (auto it1 = visited.begin(), it2 = ++visited.begin(); it2 != visited.end(); ++it1, ++it2) {
        cout << *it1 << ' ' << *it2 << '\n';
    }
}
