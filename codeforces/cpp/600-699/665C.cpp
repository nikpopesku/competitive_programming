#include <iostream>

using namespace std;

void solve() {
    string s;
    cin >> s;

    for (int i = 1; i < static_cast<int>(s.size()) - 1; ++i) {
        if (s[i - 1] == s[i]) {
            for (char c = 'a'; c < 'z'; ++c) {
                if (c != s[i - 1] && c != s[i + 1]) {
                    s[i] = c;
                    break;
                }
            }
        }
    }

    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
