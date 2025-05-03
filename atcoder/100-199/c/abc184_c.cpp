#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, X;
    string s;

    cin >> N >> X;
    cin >> s;
    int response = X;

    for (int i = 0; i < N; ++i)
    {
        if (s[i] == 'o')
        {
            ++response;
        }
        else if (response > 0)
        {
            --response;
        }
    }
    cout << response << "\n";
}
