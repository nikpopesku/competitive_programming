#include<iostream>
#include <vector>

using namespace std;

int main() {
    int N, X;
    int A[50];
    int B[50];

    cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    vector dp(X + 1, false);
    dp[0] = true;

    for (int i = 0; i < N; ++i) {
        for (int j = X; j >= 0; --j) {
            if (dp[j]) {
                for (int k = 1; k <= B[i]; ++k) {
                    if (j + A[i] * k <= X) {
                        dp[j + A[i] * k] = true;
                    }
                    if (j + A[i] * k == X) {
                        cout << "Yes\n";

                        return 0;
                    }
                }
            }
        }
    }

    cout << "No\n";
}
