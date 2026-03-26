#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, type, a, b;
    cin >> n >> q;

    vector<int> v(n);
    for (int &x: v) cin >> x;

    while (q--) {
        cin >> type >> a >> b;
    }
}
