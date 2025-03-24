#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> num(N);

    for (int i = 0; i < N; ++i) cin >> num[i];
    int commonGcd = num[0];
    for (int i = 1; i < N; ++i) commonGcd = gcd(commonGcd, num[i]);

    int response = 0;
    for (int i = 0; i < N; ++i) {
        int value = num[i] / commonGcd;
        while (value > 1) {
            if (value % 2 == 0) {
                value /= 2;
                ++response;
                continue;
            }
            if (value % 3 == 0) {
                value /= 3;
                ++response;
                continue;
            }
            if (value % 2 != 0 and value % 3 != 0) break;
        }

        if (value > 1) {
            commonGcd = -1;
            break;
        }
    }


    cout << (commonGcd < 0 ? -1 : response) << "\n";
}