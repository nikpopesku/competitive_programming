#include <iostream>
#include <vector>
#include <numeric>

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
        while (a != parent[a])
        {
            a = parent[a];
        }

        return a;
    }

    [[nodiscard]] int get_size(const int a) const
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
    vector<int> size;
    vector<int> parent;
};

struct Edge
{
    int u, v, w;

    Edge(int u, int v, int w): u(u), v(v), w(w)
    {
    }

    bool operator<(const Edge& other) const
    {
        return w < other.w;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, u, v, w;
    std::cin >> n;
    vector<Edge> edges(n-1);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v >> w;
        edges.push_back(u, v, w);
    }

    std::cout << n << std::endl;
}
