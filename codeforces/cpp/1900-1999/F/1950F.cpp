#include <iostream>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c != a + 1)
    {
        cout << "-1\n";
        return;
    }

    if (a + b + c == 1)
    {
        cout << "0\n";
        return;
    }



    int current = 1;
    int response = 1;
    int next = 0;

    for (int i = 0; i < a + b; ++i)
    {
        if (current == 0)
        {
            swap(current, next);
            ++response;
        }

        ++next;
        --current;

        if (i < a)
        {
            ++next;
        }
    }

    cout << response << "\n";

}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}