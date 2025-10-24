#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void solve() {
    int n, k, value;
    cin >> n;
    vector<int> response;
    int current_length = 0;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        int lexicographically_minimum = 0;
        for (int j = 0; j < k; ++j) {
            cin >> value;
            if (j + 1 > current_length) {
                response.push_back(value);
                ++current_length;
            } else {
                if (lexicographically_minimum == 0 && value > response[j]) {
                    lexicographically_minimum = -1;
                }
                if (lexicographically_minimum == 0 && value < response[j]) {
                    lexicographically_minimum = 1;
                }

                if (lexicographically_minimum == 1) {
                    response[j] = value;
                }
            }
        }
    }

    for (const auto &e: response) {
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}
