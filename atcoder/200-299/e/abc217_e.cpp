#include<bits/stdc++.h>

using namespace std;

string type;
int x;
deque<int> a;

void solve() {
    cin >> type;

    if (type == "1") {
        cin >> x;
        a.push_back(x);
    }

    if (type == "2") {
        cout << a.front() << '\n';
        a.pop_front();
    }

    if (type == "3") {
        sort(a.begin(), a.end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        solve();
    }
}