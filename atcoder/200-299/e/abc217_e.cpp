#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;
    string type;
    int x;
    deque<int> a;
    priority_queue<int> pq1, pq2;


    while (q--) {

        cin >> type;

        if (type == "1") {
            cin >> x;
            a.push_back(x);
            pq1.push(-x);
        }

        if (type == "2") {
            int value = a.front();
            cout << value << '\n';
            a.pop_front();
            pq2 = pq1;
            pq1 = {};

            bool popped = false;

            while (!pq2.empty()) {
                if (-value == pq2.top() and !popped) {
                    popped = true;
                } else {
                    pq1.push(pq2.top());
                }

                pq2.pop();
            }
        }

        if (type == "3") {
            a = {};
            pq2 = pq1;
            while (!pq2.empty()) {
                a.push_back(-pq2.top());
                pq2.pop();
            }
        }
    }
}