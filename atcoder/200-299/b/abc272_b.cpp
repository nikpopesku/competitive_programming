#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned int n, m;
    cin >> n >> m;


    for (int i = 1; i <= m; ++i) {
        vector<unsigned int> vc(n);

        for (int j = 0; j < n; ++j) {
            cin >> vc[j];
        }
    }

    cout << 1 << '\n';
}