#include <format>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;

    vector dp(101, vector(101, vector<float>(101, -1.0)));
    dp[100][100][100] = 0;


    for (int a = 99; a >= A; --a)
    {
        for (int b = 99; b >= B; --b)
        {
            for (int c = 99; c >= C; --c)
            {
                const int N = (a + b + c);
                dp[a][b][c] = 1 + (a / N) * dp[a + 1][b][c] + (b / N) * dp[a][b + 1][c] + (c / N) * dp[a][b][c + 1];
            }
        }
    }

    cout << format("{}", dp[A][B][C]) << "\n";
}
