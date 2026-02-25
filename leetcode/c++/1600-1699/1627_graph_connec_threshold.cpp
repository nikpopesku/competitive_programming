#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

class DisjointUnionSet {
public:
    explicit DisjointUnionSet(int size): size(size + 1, 1), parent(size + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (node == parent[node]) {
            return node;
        }

        parent[node] = find(parent[node]);

        return parent[node];
    }

    bool unionit(int a, int b) {
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
    vector<int> parent;
    vector<int> size;
};

class Solution {
public:
    vector<bool> areConnected(int n, const int threshold, const vector<vector<int> > &queries) {
        vector<bool> response;

        for (auto &q: queries) {
            const bool val = gcd(q[0], q[1]) > threshold;
            response.push_back(val);
        }

        return response;
    }

private:
    map<pair<int, int>, int> mp;

    int gcd(int a, int b) {
        if (a < b) swap(a, b);

        if (mp.contains(pair{a, b})) {
            return mp[pair{a, b}];
        }

        if (a % b == 0) {
            mp[pair{a, b}] = b;

            return b;
        }

        return gcd(b, a % b);
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > queries = {{1, 4}, {2, 5}, {3, 6}};
    for (auto e: s.areConnected(6, 2, queries)) {
        cout << boolalpha << e << ' '; //{false,false,true}
    }

    cout << '\n';

    vector<vector<int> > queries2 = {{4, 5}, {3, 4}, {3, 2}, {2, 6}, {1, 3}};
    for (auto e: s.areConnected(6, 0, queries2)) {
        cout << boolalpha << e << ' '; //{true,true,true,true,true}
    }

    cout << '\n';

    vector<vector<int> > queries3 = {{4, 5}, {4, 5}, {3, 2}, {2, 3}, {3, 4}};
    for (auto e: s.areConnected(5, 1, queries3)) {
        cout << boolalpha << e << ' '; //[false,false,false,false,false}
    }
    cout << '\n';

    vector<vector<int> > queries4 = {{6, 8}, {6, 9}, {8, 9}};
    for (auto e: s.areConnected(9, 1, queries4)) {
        cout << boolalpha << e << ' '; //[true,true,true}
    }
}
