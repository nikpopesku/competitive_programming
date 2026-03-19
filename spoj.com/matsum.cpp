#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(n + 1, vector<int>(n + 1)) {
    }

    void update(int x, int y, int val) {
    }

    int range(const int x1, const int y1, const int x2, const int y2) {
        return query(x2, y2) + query(x1 - 1, y1 - 1) - query(x2, y1 - 1) - query(x1 - 1, y2);
    }

private:
    int n;
    vector<vector<int> > tree;

    int query(int x1, int y) {
        int sum = 0;

        return sum;
    }
};

void solve() {
    int N, x1, y1, x2, y2, val;
    cin >> N;
    vector v(N, vector<int>(N));

    string type;

    while (type != "END") {
        cin >> type;

        if (type == "SET") {
            cin >> x1 >> y1 >> val;
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
