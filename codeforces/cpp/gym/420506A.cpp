#include "iostream"
#include "map"

using ll = long long;

int main() {
    int q;
    std::cin >> q;
    ll value;
    char type;
    std::map<ll, ll> mp;

    for (int i = 0; i < q; i++) {
        std::cin >> type >> value;

        if (type == 'a') mp[value] += 1;
        if (type == 't' and mp[value] > 0) mp[value]--;
        if (type == 'c') {
            std::cout << mp[value] << std::endl;
        }
    }
}