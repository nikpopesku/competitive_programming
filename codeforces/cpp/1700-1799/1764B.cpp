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
        cin >> vc[0];

        int first = vc[0];
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
            cin >> vc[i];
            while (*it > 1 and vc[i] % *it != 0) ++it;
        }


        cout << *vc.rbegin() / *it << "\n";
    }
}