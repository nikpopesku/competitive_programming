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
    for (int i = 0; i < N; ++i) {
        if (S[i] != 0) {
            int count_1 = 0;
            int count_2 = 0;
            int j = i;
            while (j < N and S[j] != 0) {
                if (S[j] == 1) ++count_1;
                if (S[j] == 2) ++count_2;
                ++j;
            }
            argument = count_1 > count_2 ? -1 : 1;
            ++response;
            for (int k = i; k < j; ++k) S[k] = (S[k] + argument) % 3;
            --i;
        }
    }

    cout << response << endl;
}