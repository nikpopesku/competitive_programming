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

    vector dp(X+1, vector(N, -1));
}
