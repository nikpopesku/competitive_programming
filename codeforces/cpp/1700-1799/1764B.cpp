#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, value;
        cin >> n;
        cin >> value;
        int first = value;
        int factor = 2;
        set<int> factors = {1};

        while (factor <= first) {
            if (first % factor == 0) {
                first /= factor;
                if (factors.find(factor) == factors.end()) factors.insert(factor);
                continue;
            }

            ++factor;
        }


        auto it = factors.rbegin();
        for (int i = 1; i < n; ++i) {
            cin >> value;
            while (*it > 1 and value % *it != 0) ++it;
        }


        cout << value / *it << "\n";
    }
}