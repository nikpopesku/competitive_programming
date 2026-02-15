#include<iostream>
#include <numeric>
#include <vector>


using namespace std;

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(const int size) : size(size + 1), parent(size + 1) {
        iota(parent.begin(), parent.end(), 0);
        maxsize = 1;
        number_components = size;
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

        maxsize = max(maxsize, size[parent_a]);
        --number_components;

        return true;
    }

    [[nodiscard]] int get_maxsize() const {
        return maxsize;
    }

    [[nodiscard]] int get_number_components() const {
        return number_components;
    }

private:
    vector<int> size;
    vector<int> parent;
    int maxsize;
    int number_components;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;
    vector adj(n + 1, vector<int>());
    DisjointSetUnion dsu(n);
    vector<pair<int, int> > response(m);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        dsu.unionit(a, b);

        response[i] = {dsu.get_number_components(), dsu.get_maxsize()};
    }

    for (auto [fst, snd]: response) {
        cout << fst << ' ' << snd << '\n';
    }
}
