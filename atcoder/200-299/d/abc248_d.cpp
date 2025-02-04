#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> vc(n);

    for (int i = 0; i < n; ++i) {
        cin >> vc[i];
    }

    cin >> q;
    int left, right, x;

    for (int i = 0; i < q; ++i) {
        cin >> left >> right >> x;

        cout << 1 << endl;
    }

}