#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }

    return a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> vc(n);

        for (int i = 0; i < n; ++i) cin >> vc[i];
        int first = *vc.begin();
        int factor = 2;
        set<int> factors = {1};

        while (factor <= first) {
            if (first % factor == 0) {
                first /= factor;
                if (factors.find(factor) == factors.end()) factors.insert(factor);
            } else {
                ++factor;
            }
        }

        bool condition = true;
        auto it = factors.rbegin();

        while (condition) {
            condition = false;

            for (auto it2 = ++vc.begin(); it2 != vc.end(); ++it2) {
                if (*it2 % *it != 0) {
                    ++it;
                    condition = true;
                    break;
                }
            }
        }


        cout << *vc.rbegin() / *it << "\n";
    }
}