#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> price(n, 0);
    vector<int> pages(n, 0);

    for (int i = 0; i <= n; ++i) cin >> price[i];
    for (int i = 0; i <= n; ++i) cin >> pages[i];
    int response = 0;

    cout << response << "\n";
}