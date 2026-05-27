#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string s;
    cin >> s;
    const int n = static_cast<int>(s.size());

    string t, u;

    for (int i = 0; i < n; ++i) {
        while (!t.empty() && t.back() <= s[i]) {
            u += t.back();
            t.pop_back();
        }

        t += s[i];
    }

    while (!t.empty()) {
        u += t.back();
        t.pop_back();
    }

    cout << u;
}
