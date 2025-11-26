#include <iostream>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string t;
        cin >> t;

        if (set s(t.begin(), t.end()); s.size() == 1) {
            cout << t;

            continue;
        }

        string value;
        value += t[0];
        value += t[0] == '1' ? '0' : '1';

        for (auto i = 0; i < static_cast<int>(t.size()); ++i) {
            cout << value;
        }
    }
}
