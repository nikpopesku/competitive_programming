#include <bits/stdc++.h>

using namespace std;

// input data
int N, M;


int main() {

    vector<string> S;
    cin >> N >> M;
    S.resize(N);

    for (int i = 0; i < N; i++)
        cin >> S[i];

    vector vc(4 * N, vector<int>(4 * M, 1));
    for (int i = 0; i < N; ++i) {
        for (size_t j = 0; j < S.size(); ++j) {
            for (int vi = i * 4; vi < i * 4 + 4; ++vi) {
                for (int vj = j * 4; vj < j * 4 + 4; ++vj) {
                    if (S[i][j] == '\\' && vi == vj) {
                        vc[vi][vj] = 0;
                        continue;
                    }
                    if (S[i][j] == '/' && vi + vj == 3) {
                        vc[vi][vj] = 0;
                    }
                }
            }
        }
    }

    cout << 1 << endl;
}