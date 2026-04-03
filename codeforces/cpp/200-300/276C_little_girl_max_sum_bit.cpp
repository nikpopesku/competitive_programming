#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define  ll long long

class Bit {
public:
    Bit (int sz): n(sz), tree(sz+1, 0) {

    }

    void update(int l, int r) {

    }

    int query(int l, int r) {

    }
private:
    int n;
    vector<int> tree;
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, l, r;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    Bit bt(n);

    while (q--) {
        cin >> l >> r;
        bt.update(l, r);
    }

    cout << bt.query(1, n) << '\n';
}
