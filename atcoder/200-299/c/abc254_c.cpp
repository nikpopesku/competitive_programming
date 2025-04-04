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

    for (int i = 0; i < k; ++i) {
        vector<int> pos;

        int j = i;

        while (j <= n) {
            pos.push_back(vc[j]);
            j += k;
        }

        sort(pos.begin(), pos.end());

        j = i;
        for (auto it = pos.begin(); it != pos.end(); ++it, j += k) {
            vc[j] = *it;
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