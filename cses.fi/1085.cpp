#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> vc(n);

    for (int i = 0; i < n; ++i) {
        cin >> vc[i];
    }
}