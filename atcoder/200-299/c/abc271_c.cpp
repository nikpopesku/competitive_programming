#include <iostream>
#include <set>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    ll value;
    ll duplicates = 0;
    set<ll> s;

    for (size_t i = 1; i <= n; ++i) {
        cin >> value;
        if (s.count(value) == 0) {
            s.insert(value);
        } else {
            ++duplicates;
        }

    }

    ll response = 0;

    while (!s.empty()) {
        if (*s.begin() == response + 1) {
            s.erase(s.begin());
        } else {
            if (duplicates > 0) {
                --duplicates;
            } else {
                if (s.empty()) break;
                s.erase(std::prev(s.end()));
            }

            if (duplicates > 0) {
                --duplicates;
            } else {
                if (s.empty()) break;
                s.erase(std::prev(s.end()));
            }
        }

        ++response;
    }

    cout << response << endl;
}