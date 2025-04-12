#include<iostream>
#include<vector>
#include<numeric>
#include<set>

using namespace std;

class DisjointSetUnion
{
public:
    explicit DisjointSetUnion(const int size): size(size, 1), parent(size), uniq(), max_size(1)
    {
        iota(parent.begin(), parent.end(), 0);
        uniq = set(parent.begin() + 1, parent.end());
    }

    [[nodiscard]] int find(int index) const
    {
        while (parent[index] != index)
        {
            index = parent[index];
        }

        return index;
    }

    [[nodiscard]] size_t get_uniq() const
    {
        return uniq.size();
    }

    [[nodiscard]] int get_max_size() const
    {
        return max_size;
    }

    bool unify(const int a, const int b)
    {
        if (find(a) == find(b)) return false;

        int parent_a = find(a);
        int parent_b = find(b);

        if (size[parent_a] < size[parent_b]) swap(parent_a, parent_b);

        size[parent_a] += size[parent_b];
        parent[parent_b] = parent_a;
        max_size = max(max_size, size[parent_a]);
        uniq.erase(parent_b);

        return true;
    }

    [[nodiscard]] bool equal(const int a, const int b) const
    {
        return find(a) == find(b);
    }

private:
    vector<int> size;
    vector<int> parent;
    set<int> uniq;
    int max_size;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    DisjointSetUnion dsu(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int val1, val2;
        cin >> val1 >> val2;
        dsu.unify(val1, val2);

        cout << dsu.get_uniq() << " " << dsu.get_max_size() << "\n";
    }

    cout << 1 << "\n";
}
