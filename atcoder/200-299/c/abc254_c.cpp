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

    for (int i = 1; i <= n - k; ++i) {
        int j = i;
        while (j + k <= n and vc[j] > vc[j + k]) {
            swap(vc[j], vc[j + k]);
            j += k;
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