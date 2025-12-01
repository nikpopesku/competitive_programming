#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        vector<int> v(10, false);

        if (x > 45) {
            cout << "-1\n";

            continue;
        }

        while (x > 0) {
            for (int i = 9; i >= 1; --i) {
                if (!v[i] && x - i >= 0) {
                    v[i] = true;
                    x -= i;
                }
            }
        }

        for (int i = 1; i <= 9; ++i) {
            if (v[i]) {
                cout << i;
            }
        }

        cout << "\n";
    }
}
