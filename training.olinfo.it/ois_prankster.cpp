// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<int> S;

    cin >> N;
    S.resize(N + 1);
    for (int i = 0; i < N; i++) cin >> S[i];

    int response = 0;
    int count_1 = 0;
    int count_2 = 0;
    int argument;
    bool condition = true;
    while (condition) {
        condition = false;

        for (int i = 0; i <= N; i++) {
            if (S[i] == 1) ++count_1;
            if (S[i] == 2) ++count_2;
            if (S[i] == 0 and (count_1 or count_2)) {
                argument = count_1 > count_2 ? -1 : 1;

                for (int j = i - count_2 - count_1; j < i; ++j) {
                    S[j] += argument;
                    if (S[j] == 3) S[j] = 0;
                }

                count_1 = 0;
                count_2 = 0;
                ++response;
                condition = true;
            }
        }
    }

    cout << response << endl;
}