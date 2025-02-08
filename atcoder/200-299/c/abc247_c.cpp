#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> vc(n+1);
    vc[0] = "0";
    vc[1] = "1";
    vc[2] = "121";
    vc[3] = "1213121";

    for (auto i = 4; i <= n; ++i) {
        vc[i] = vc[i - 1] + to_string(i) + vc[i - 1];
    }

    for (size_t i = 0; i < vc[n].size(); ++i) {
        cout << vc[n][i] << (i < vc[n].size() - 1 ? " " : "\n");
    }
}