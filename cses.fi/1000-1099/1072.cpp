#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        long long total = static_cast<long long>(i) * i * (static_cast<long long>(i) * i - 1) / 2;
        long long attacking = 0;
        if (i > 2) {
            attacking = 4LL * (i - 1) * (i - 2);
        }
        cout << total - attacking << "\n";
    }

    return 0;
}
