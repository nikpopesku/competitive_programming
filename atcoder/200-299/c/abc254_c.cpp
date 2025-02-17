#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> vc(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> vc[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (vc[i] != i and abs(vc[i] - i) % k == 0) {
            swap(vc[i], vc[vc[i]]);
        }
    }

    string response = "Yes";
    for (int i = 1; i <= n; ++i) {
        if (vc[i] < vc[i - 1]) {
            response = "No";
            break;
        }
    }

    cout << response << '\n';
}