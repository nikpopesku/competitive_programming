#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;

    vector dp(101, vector(101, vector(101, -1.0)));

    for (int a = 100; a >= A; --a)
    {
        for (int b = 100; b >= B; --b)
        {
            for (int c = 100; c >= C; --c)
            {
                if (a == 100 or b == 100 or c == 100) dp[a][b][c] = 0.0;
            }
        }
    }

    for (int a = 99; a >= A; --a)
    {
        for (int b = 99; b >= B; --b)
        {
            for (int c = 99; c >= C; --c)
            {
                const double N = a + b + c;
                dp[a][b][c] = 1.0 + (a / N) * dp[a + 1][b][c] + (b / N) * dp[a][b +
                    1][c] + (c / N) * dp[a][b][c + 1];
            }
        }
    }

    cout << std::setprecision(10) << dp[A][B][C] << "\n";
}
