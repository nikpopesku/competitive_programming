#include <iostream>
#include <vector>

using namespace std;

int calc_response(const int& a, const int& b, int& response, int& current_side, int& current_time)
{
    if (int min_val = current_side != b ? 1 : 0; a >= current_time + min_val)
    {
        const int val = a - current_time - min_val;
        response += val / 2 * 2;
        current_time = a - min_val;
    }

    if (a > current_time)
    {
        ++response;
    }

    current_time = a;
    current_side = b;

    return response;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a, b;
        int current_side = 0;
        int current_time = 0;
        int response = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;

            response = calc_response(a, b, response, current_side, current_time);
        }

        cout << max(calc_response(m, 0, response, current_side, current_time), calc_response(m, 1, response, current_side, current_time)) << "\n";
    }

    return 0;
}
