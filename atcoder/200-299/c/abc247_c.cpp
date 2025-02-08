#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int N = 16;

    vector<string> vc(N);
    vc[0] = "1";
    vc[1] = "121";
    vc[2] = "1213121";

    for (auto i = 3; i < N; ++i) {
        vc[i] = vc[i - 1] + to_string(i + 4) + vc[i - 1];
    }

    for (auto i = 0; i < vc[n].size(); ++i) {
        cout << vc[n][i] << (i < vc[n].size() - 1 ? " " : "\n");
    }
}