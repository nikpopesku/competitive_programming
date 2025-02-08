#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vc(n), vc2(n);

    for (auto i = 0; i < n; ++i) {
        cin >> vc[i];
    }

    for (auto i = 0; i < n; ++i) {
        vc2[vc[i] - 1] = i + 1;
    }

    for (auto i = 0; i < n; ++i) cout << vc2[i] << (i < n -1 ? ' ' : '\n');
}