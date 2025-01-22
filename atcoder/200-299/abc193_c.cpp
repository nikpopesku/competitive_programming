#include <iostream>
#include <unordered_set>

using ll = long long;

int main() {
    std::unordered_set<ll> s;
    ll n;
    std::cin >> n;

    for (ll i = 2, value = i * i; value <= n; i++) {
        while (value <= n) {
            s.insert(value);
            value *= i;
        }
    }

    std::cout << n - s.size() << std::endl;
}