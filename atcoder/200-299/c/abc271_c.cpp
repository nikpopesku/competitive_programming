#include <iostream>
#include <queue>

using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    ll value;
    priority_queue<ll> pq_low, pq_high;

    for (auto i = 1; i <= n; ++i) {
        cin >> value;
        pq_low.push(-1 * value);
        pq_high.push(value);
    }

    ll response = 0;
    bool condition = true;

    while (condition and !pq_low.empty()) {
        value = pq_low.top();

        if (value == response + 1) {
            pq_low.pop();
            ++response;
        } else if (value != response + 1) {
            if (pq_high.empty()) {
                condition = false;
                break;
            }
            ll value1 = pq_high.top();
            if (value1 <= value) {
                condition = false;
                break;
            }
            pq_high.pop();
            if (pq_high.empty()) {
                condition = false;
                break;
            }
            ll value2 = pq_high.top();
            if (value2 <= value) {
                condition = false;
                break;
            }
            pq_high.pop();
            response += 1;
        }
    }

    cout << response << endl;
}