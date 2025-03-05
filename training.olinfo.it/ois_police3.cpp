// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> T(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];

    vector<vector<int>> dp(N, vector<int>(2));
    dp[0][0] = T[0]; //stop
    dp[0][1] = 0; //go

    for (int i = 1; i < dp.size(); ++i) {
        dp[i][0] = T[i] + min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0];
    }

    cout << min(dp[N - 1][0], dp[N - 1][1]) << endl;
    return 0;
}