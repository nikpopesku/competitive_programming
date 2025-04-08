#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector leap(N, vector<int>(N, -1));
    leap[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cout << leap[i][j] << " ";
        cout << "\n";
    }
}