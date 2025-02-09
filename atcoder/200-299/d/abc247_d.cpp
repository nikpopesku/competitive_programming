#include <iostream>
#include <queue>

using namespace std;

#define ll long long

int main() {
    int q, type;
    ll x, c;
    cin >> q;
    queue<ll> qq;

    for (int i = 0; i < q; ++i) {
        std::cin >> type;
        if (type == 1) {
            std::cin >> x >> c;
            while (c-- > 0) {
                qq.push(x);
            }

        }

        if (type == 2) {
            ll response = 0;
            std::cin >> c;


            while (c-- > 0) {
                response += qq.front();
                qq.pop();
            }

            std::cout << response << std::endl;
        }
    }
}