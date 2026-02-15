#include<iostream>
#include <numeric>
#include <vector>


using namespace std;

class DisjointSetUnion {
public:
    DisjointSetUnion(int size): size(size+1), parent(size+1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(const int node) {
        if (node == parent[node]) {
            return node;
        }

        parent[node] = find(parent[node]);

        return parent[node];
    }
private:
    vector<int> size;
    vector<int> parent;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

}
