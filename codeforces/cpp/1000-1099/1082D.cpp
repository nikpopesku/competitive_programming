#include <iostream>
#include <vector>


using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> leafes;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= 1) {
            leafes.push_back(a[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
