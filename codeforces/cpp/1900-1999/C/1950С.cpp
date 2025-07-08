#include <iostream>

using namespace std;

void solve()
{
    string inp;
    cin >> inp;

    if (inp == "00:00")
    {
        cout << "12:00 AM\n";

        return;
    }

    int hour = (inp[0] - '0') * 10 + (inp[1] - '0');
    string part_of_day = "AM";

    if (hour >= 12 and hour <= 23)
    {
        part_of_day = "PM";
        if (hour >= 13)
        {
            hour -= 12;
        }
    }

    if (hour < 10)
    {
        cout << '0';
    }
    cout << hour << ":" << inp[3] << inp[4] << " " << part_of_day << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
