#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n;

        vector<int> vc_a(n);
        vector<int> vc_b(n);

        for (int j = 0; j < n; ++j) {
            cin >> vc_a[j] >> vc_b[j];
        }
    }
}
