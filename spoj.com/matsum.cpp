#include <iostream>
#include <stack>
#include <vector>

using namespace std;

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
