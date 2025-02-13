#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);

    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    int ans = 0;
    for (int v = n - 1; v; v = p[v]) ans++;
    cout << ans << '\n';
}