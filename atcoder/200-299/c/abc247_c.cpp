#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> vc(n);
    vc[0] = "1";
    vc[1] = "121";
    vc[2] = "1213121";

    for (auto i = 3; i < n; ++i) {
        vc[i] = vc[i - 1] + to_string(i + 1) + vc[i - 1];
    }

    for (auto i = 0; i < vc[n - 1].size(); ++i) {
        cout << vc[n - 1][i] << (i < vc[n - 1].size() - 1 ? " " : "\n");
    }
}