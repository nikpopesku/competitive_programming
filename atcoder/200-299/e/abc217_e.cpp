#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q, value;
    cin >> q;
    string type;
    int x;
    priority_queue<int> pq;
    deque<int> dq;


    while (q--) {

        cin >> type;

        if (type == "1") {
            cin >> x;
            dq.push_back(x);
        }

        if (type == "2") {
            if (!pq.empty()) {
                value = -pq.top();
                pq.pop();
            } else {
                value = dq.front();
                dq.pop_front();
            }

            cout << value << '\n';
        }

        if (type == "3") {
            while (!dq.empty()) {
                pq.push(-dq.front());
                dq.pop_front();
            }
        }
    }
}