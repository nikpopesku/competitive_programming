#include <iostream>
#include <set>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    ll value;
    multiset<ll> s;

    for (size_t i = 1; i <= n; ++i) {
        cin >> value;
        s.insert(value);
    }

    ll response = 0;

    while (!s.empty()) {
        if (*s.begin() == response + 1) {
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