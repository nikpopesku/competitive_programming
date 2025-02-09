#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

#define ll long long

int main() {
    ll n, k, x, value, response = 0;
    cin >> n >> k >> x;

    priority_queue<ll> pq;

    for (auto i = 0; i < n; ++i) {
        cin >> value;
        pq.push(value);
        response += value;
    }

    while (!pq.empty() and k > 0) {
        value = pq.top();
        ll cnt = std::min(value / x, k);

        if (cnt > 0) {
            response -= cnt * x;
            value -= cnt * x;
            k -= cnt;
        } else {
            response -= std::min(value, x);
            value = 0;
            --k;
        }

        pq.pop();
        if (value > 0) {
            pq.push(value);
        }
    }

    cout << response << endl;

}