#include <iostream>
#include <vector>

using namespace std;

int calc_response(const int& new_time, const int& new_side, int& response, int& current_side, int& current_time)
{
    if (const int min_val = current_side != new_side ? 1 : 0; new_time >= current_time + min_val)
    {
        const int val = new_time - current_time - min_val;
        response += val / 2 * 2;
        current_time = new_time - min_val;
    }

    if (new_time > current_time)
    {
        ++response;
    }

    current_time = new_time;
    current_side = new_side;

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
        int new_time, new_side;
        int current_side = 0;
        int current_time = 0;
        int response = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> new_time >> new_side;

            response = calc_response(new_time, new_side, response, current_side, current_time);
        }

        cout << max(calc_response(m, 0, response, current_side, current_time),
                    calc_response(m, 1, response, current_side, current_time)) << "\n";
    }

    return 0;
}
