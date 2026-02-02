#include<bits/stdc++.h>

using namespace std;

void calc() {
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    cin >> n;

    vector<vector<int> > adj;
    vector<int> distance(n, 0);

    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 for (int i = 0; i < n; ++i) {
        cout << distance[i] << ' ';
    }

    cout << "1\n";
}
