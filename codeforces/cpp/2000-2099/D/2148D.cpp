#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, value;
        cin >> n;
        int current_state = 0;
        multiset<int> s;
        long long response = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> value;
            if (value % 2 == 0)
            {
                response += value;
            }
            else
            {
                s.insert(value);
            }
        }

        if (s.empty())
        {
            cout << "0\n";

            continue;
        }

        while (!s.empty())
        {
            if (!current_state)
            {
                const int largest = *prev(s.end());
                s.erase(prev(s.end()));
                response += largest;
                current_state = 1;
            }
            else
            {
                s.erase(s.begin());
                current_state = 0;
            }
        }

        cout << response << "\n";
    }

    return 0;
}
