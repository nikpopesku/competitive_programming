#include<bits/stdc++.h>

using namespace std;

constexpr int MD = 1e9 + 7;

int pow(int a, int b) {
    int response = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            response *= a;
            --b;
        } else {
            a = a * a;
            b >>= 1;
        }
    }

    return response;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector occ(26, 0);
    vector<int> fact(1e6, 0);
    string s;
    cin >> s;
    for (char i : s) {
        ++occ[i - 'a'];
    }
}
