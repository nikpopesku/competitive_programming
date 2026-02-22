#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class DisjointUnionSet {
public:
    explicit DisjointUnionSet(const int size) : size(size, 1), parent(size) {
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

private:
    vector<int> size;
    vector<int> parent;
};

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        const int n = static_cast<int>(row.size());
        DisjointUnionSet dsu(n);
        int counter = 0;

        for (int i = 0; i < n; i += 2) {
            int p1 = row[i] / 2;
            int p2 = row[i+1] / 2;

            if (dsu.unionit(p1, p2)) {
                ++counter;
            }
        }

        return counter;
    }
};

int main() {
    auto s = Solution();

    vector<int> row = {0, 2, 1, 3}; //1
    cout << s.minSwapsCouples(row) << endl;

    vector<int> row2 = {3, 2, 0, 1}; //0
    cout << s.minSwapsCouples(row2) << endl;
}
