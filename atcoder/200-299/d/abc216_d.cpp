#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<queue<int>> Q(M);
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            a--;
            Q[i].push(a);
        }
    }
    vector<vector<int>> p(N);
    for (int i = 0; i < M; i++) {
        p[Q[i].front()].push_back(i);
    }
    queue<int> Q2;
    for (int i = 0; i < N; i++) {
        if (p[i].size() == 2) {
            Q2.push(i);
        }
    }
    int cnt = 0;
    while (!Q2.empty()) {
        int c = Q2.front();
        Q2.pop();
        cnt++;
        int a = p[c][0];
        int b = p[c][1];
        Q[a].pop();
        Q[b].pop();
        if (!Q[a].empty()) {
            p[Q[a].front()].push_back(a);
            if (p[Q[a].front()].size() == 2) {
                Q2.push(Q[a].front());
            }
        }
        if (!Q[b].empty()) {
            p[Q[b].front()].push_back(b);
            if (p[Q[b].front()].size() == 2) {
                Q2.push(Q[b].front());
            }
        }
    }
    if (cnt == N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}