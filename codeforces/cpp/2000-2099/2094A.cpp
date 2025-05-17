#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string t;
    getline(cin, t);
    string country;
    int tt = stoi(t);

    while (tt--)
    {
        string response;

        getline(cin, country);

        for (int i = 0; i < country.size(); ++i)
        {
            if (i == 0 || country[i - 1] == ' ')
            {
                response += country[i];
            }
        }

        cout << response << "\n";
    }
}
