#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        unordered_set<int> s;
        int response = 0;

        for (int num = 1; num <= x; ++num) {
            int i = num;

            while (i) {
                int digit = i % 10;

                i = i / 10;

                if (s.contains(digit)) {
                    response = -1;
                    break;
                }

                s.insert(digit);
                response += digit;
            }

            if (response == x) {
                cout << num << "\n";
                break;
            }

            response = -1;
        }

        if (response == -1) {
            cout << "-1\n";
        }
    }
}
