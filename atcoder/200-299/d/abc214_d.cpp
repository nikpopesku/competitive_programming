#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class DisjointSetUnion
{
public:
    explicit DisjointSetUnion(const int size): size(size, 1), parent(size)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    [[nodiscard]] int find(int a) const
    {
        while (a != parent[a]) a = parent[a];

        return a;
    }

    [[nodiscard]] long long get_size(const int a) const
    {
        return size[find(a)];
    }


    bool unify(const int a, const int b)
    {
        int parent_a = find(a);
        int parent_b = find(b);

        if (parent_a == parent_b) return false;

        if (size[parent_a] < size[parent_b]) swap(parent_a, parent_b);

        size[parent_a] += size[parent_b];
        parent[parent_b] = parent_a;

        return true;
    }

private:
    vector<long long> size;
    vector<int> parent;
};

struct Edge
{
    int u, v;
    long long w;

    bool operator<(const Edge& other) const
    {
        return w < other.w;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, u, v;
    long long w;
    std::cin >> n;
    vector<Edge> edges;
    edges.reserve(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v >> w;
        edges.emplace_back(u - 1, v - 1, w);
    }

    sort(edges.begin(), edges.end());

    long long response = 0;
    DisjointSetUnion dsu(n);

    for (auto [u, v, w] : edges)
    {
        const long long size_u = dsu.get_size(u);
        const long long size_v = dsu.get_size(v);
        response += w * size_u * size_v;

        dsu.unify(u, v);
    }

    std::cout << response << std::endl;
}
