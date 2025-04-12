#include<iostream>
#include<vector>
#include<numeric>
#include<utility>

using namespace std;

class DisjointSet
{
public:
    explicit DisjointSet(const int size): parents(size), size(size, 1)
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

    [[nodiscard]] bool unite(int a, int b)
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


    cout << 1 << "\n";
}
