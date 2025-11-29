#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        int response = 0;

        for (int num = 1; num <= 100; ++num) {
            response = 0;
            int i = num;
            unordered_set<int> s;

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
                response = num;
                break;
            }

            response = 0;


        }

        cout << (response != 0 ? response : -1) << "\n";
    }
}
