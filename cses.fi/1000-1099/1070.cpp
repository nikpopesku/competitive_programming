#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1";

        return 0;
    }

    if (n <= 3) {
        cout << "NO SOLUTION\n";

        return 0;
    }

    int i, j;
    for (i = 1, j = n / 2 + 1; i <= n / 2; ++i, ++j) {
        cout << j << " " << i << " ";
    }

    if (n % 2 == 1) {
        cout << j;
    }
}
