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
        vector<int> values_true;
        for (int j = 0; j <= X; ++j) {
            if (dp[j]) {
                for (int k = 1; k <= B[i]; ++k) {
                    if (j + A[i] * k <= X && !dp[j + A[i] * k]) {
                        values_true.push_back(j + A[i] * k);
                        if (j + A[i] * k == X) {
                            cout << "Yes\n";

                            return 0;
                        }
                    }
                }
            }
        }
        for (const auto elem: values_true) {
            dp[elem] = true;
        }
    }

    cout << "No\n";
}
