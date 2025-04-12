#include<iostream>
#include<vector>
#include<numeric>
#include<utility>
#include<set>

using namespace std;

class DisjointSet
{
public:
    explicit DisjointSet(const int size): size(size, 1), parents(size)
    {
        iota(parents.begin(), parents.end(), 0);
    }

    [[nodiscard]] int find(int index) const
    {
        while (parents[index] != index)
        {
            index = parents[index];
        }

        return index;
    }

    bool unite(int a, int b)
    {
        if (find(a) == find(b)) return false;

        if (size[a] < size[b]) swap(a, b);

        parents[b] = a;
        size[a] += size[b];

        return true;
    }

    [[nodiscard]] bool equal(const int a, const int b) const
    {
        return find(a) == find(b);
    }

private:
    vector<int> size;
    vector<int> parents;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DisjointSet dsu(n);

    for (int i = 0; i < m; ++i)
    {
        int city1, city2;

        cin >> city1 >> city2;

        if (!dsu.equal(city1 - 1, city2 - 1)) dsu.unite(city1 - 1, city2 - 1);
    }

    int response = 0;
    for (int i = 0; i < n; ++i) if (i > 0 and !dsu.equal(i, i - 1)) response++;

    set<int> visited;

    for (int i = 0; i < n; ++i)
    {
        if (int parent = dsu.find(i); !visited.count(parent))visited.insert(parent);
    }

    cout << visited.size() - 1 << "\n";

    for (auto it1 = visited.begin(), it2 = ++visited.begin(); it2 != visited.end(); ++it1, ++it2)
    {
        cout << *it1 + 1 << " " << *it2 + 1 << "\n";
    }
}
