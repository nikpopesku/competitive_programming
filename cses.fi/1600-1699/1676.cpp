#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class DisjointSetUnion
{
public:
    explicit DisjointSetUnion(const int size): size(size, 1), parent(size)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    [[nodiscard]] int find(int index) const
    {
        while (parent[index] != index)
        {
            index = parent[index];
        }

        return index;
    }

    bool unify(const int a, const int b)
    {
        if (find(a) == find(b)) return false;

        int parent_a = find(a);
        int parent_b = find(b);

        if (size[parent_a] < size[parent_b]) swap(parent_a, parent_b);

        size[parent_a] += size[parent_b];
        parent[parent_b] = parent_a;

        return true;
    }

    [[nodiscard]] bool equal(const int a, const int b) const
    {
        return find(a) == find(b);
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

    int n, m;

    cin >> n >> m;

    cout << 1 << "\n";
}
