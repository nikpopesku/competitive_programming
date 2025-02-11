#include <iostream>
#include <set>

using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    ll value;
    multiset<ll> s;

    for (auto i = 1; i <= n; ++i) {
        cin >> value;
        s.insert(value);
    }

    ll response = 0;

    while (!s.empty()) {
        value = *s.begin();

        if (value == response + 1) {
            s.erase(s.begin());
        } else {
            if (s.empty()) break;
            s.erase(std::prev(s.end()));
            if (s.empty()) break;
            s.erase(std::prev(s.end()));
        }

        ++response;
    }

    cout << response << endl;
}