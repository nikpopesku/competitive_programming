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
        int n, value;
        cin >> n;

        set<int> vc;

        for (int i = 0; i < n; ++i) {
            cin >> value;
            vc.insert(value);
        }

        int firstGcd = *vc.begin();


        for (auto it = ++vc.begin(); it != vc.end(); ++it) {
            firstGcd = gcd(firstGcd, *it);
        }

        auto start = firstGcd;


        while (firstGcd < *(--vc.end())) {
            if (vc.find(firstGcd) != vc.end()) {
                vc.insert(firstGcd);
            }

            firstGcd += start;
        }

        cout << vc.size() << "\n";
    }
}