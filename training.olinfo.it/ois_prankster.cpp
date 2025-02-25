#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<int> S;

    cin >> N;
    S.resize(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    int response = 0;
    int argument;
    int prev_argument = 0;


    for (int i = 0; i <= N; i++) {
        if (S[i] != 0) {
            argument = S[i] == 1 ? -1 : 1;

            if (argument != prev_argument) {
                ++response;
                prev_argument = argument;
            }
        }

        if (S[i] == 0) prev_argument = 0;
    }

    cout << response << endl;
}