#include <iostream>
#include <vector>

using namespace std;

int calc_response(const int& new_time, const int& new_side, const int& response, const int& current_side, const int& current_time)
{
    if (current_side != new_side)
    {
        return response + new_time - current_time - ((new_time - current_time) % 2 == 0 ? 1 : 0);
    }

    return response + new_time - current_time - ((new_time - current_time) % 2 == 1 ? 1 : 0);
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

            current_time = new_time;
            current_side = new_side;
        }

        cout << max(calc_response(m, 0, response, current_side, current_time),
                    calc_response(m, 1, response, current_side, current_time)) << "\n";
    }

    return 0;
}
