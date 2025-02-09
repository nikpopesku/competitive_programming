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
    }

    while (!pq.empty() and k > 0) {
        value = pq.top();
        value -= x;
        if (value < 0) value = 0;
        pq.pop();
        if (value > 0) {
            pq.push(value);
        }
        --k;
    }


}