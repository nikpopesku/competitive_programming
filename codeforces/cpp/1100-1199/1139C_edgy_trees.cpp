#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

constexpr int MOD = 1e9 + 7;

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(const int size) : size(size + 1, 1), parent(size + 1) {
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

    vector<int> get_size() {
        return size;
    }

private:
    vector<int> size;
    vector<int> parent;
};

int main() {
    int n, k, u, v, x;
    cin >> n >> k;
    DisjointSetUnion dsu(n);

    for (int i = 1; i <= n - 1; ++i) {
        cin >> u >> v >> x;
        if (x == 0) {
            dsu.unionit(u, v);
        }
    }

    long long response = n;
    for (int i = 1; i < k; ++i) {
        response = response * n % MOD;
    }

    vector visited(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (const int parent = dsu.find(i); !visited[parent]) {
            long long value = dsu.get_size()[parent];
            for (int j = 1; j < k; ++j) {
                value = value * dsu.get_size()[parent] % MOD;
            }

            visited[parent] = true;
            response = (response - value % MOD + MOD) % MOD;
        }
    }

    cout << response << '\n';
}
