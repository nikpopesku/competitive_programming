#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vc(n);

    for (auto i = 0; i < n; ++i) {
        cin >> vc[i];
    }
}