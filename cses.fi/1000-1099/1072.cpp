#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long total = 0;
    long long attacking = 0;

    for (long long i = 1; i <= n; ++i) {
        total = i * i * (i * i - 1) / 2;

        if (i > 2) {
            attacking = 2 * 2 * (i - 1) * (i - 2);
        }

        cout << (total - attacking) << "\n";
    }
}
