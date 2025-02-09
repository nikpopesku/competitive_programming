#include <iostream>
#include <queue>

using namespace std;

#define ll long long

int main() {
    int q, type;
    ll x, c;
    cin >> q;
    deque<pair<ll, ll>> qq;

    for (int i = 0; i < q; ++i) {
        std::cin >> type;
        if (type == 1) {
            std::cin >> x >> c;
            qq.insert(qq.end(), {x, c});
        }

        if (type == 2) {
            ll response = 0;
            std::cin >> c;

            while (c > 0) {
                auto value = qq.front();
                qq.pop_front();
                if (value.second >= c) {
                    response += c * value.first;
                    value.second -= c;
                    qq.push_front(value);
                    c = 0;
                } else {
                    c -= value.second;
                    response += value.second * value.first;
                }
            }


            std::cout << response << std::endl;
        }
    }
}