#include<iostream>
#include<queue>
#include<vector>
#include<numeric>
#include<set>

using namespace std;

class DisjointSetUnion
{
public:
    explicit DisjointSetUnion(const int size): size(size, 1), parent(size), max_size(1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    [[nodiscard]] bool equal(const int a, const int b) const
    {
        return find(a) == find(b);
    }

    [[nodiscard]] int find(int a) const
    {
        while (a != parent[a]) a = parent[a];

        return a;
    }

    [[nodiscard]] int get_max_size() const
    {
        return max_size;
    }

    bool unify(const int a, const int b)
    {
        int parent_a = find(a);
        int parent_b = find(b);

        if (parent_a == parent_b) return false;

        if (size[parent_a] < size[parent_b]) swap(parent_a, parent_b);

        size[parent_a] += size[parent_b];
        parent[parent_b] = parent_a;
        max_size = max(max_size, size[parent_a]);

        return true;
    }

private:
    vector<int> size;
    vector<int> parent;
    int max_size;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int city1, city2;
    long long cost;
    DisjointSetUnion dsu(n + 1);

    priority_queue<tuple<long long, int, int>> q;

    for (int i = 0; i < m; ++i)
    {
        cin >> city1 >> city2 >> cost;
        q.emplace(cost, city1, city2);
    }

    long long response = 0;

    while (dsu.get_max_size() < n and !q.empty())
    {
        auto [cost, city1, city2] = q.top();
        q.pop();

        if (dsu.unify(city1, city2)) response += cost;
    }

    if (dsu.get_max_size() == n)
    {
        cout << response << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}
