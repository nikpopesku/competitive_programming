#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    int n;
    int m;
    int k;
    int a;
    int b;
    int c;
    int d;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m >> k;

        cin >> a >> b;

        string answer = "YES\n";

        for (int j = 0; j < k; j++) {
            cin >> c >> d;
            if ((a + b) % 2 == (c + d) % 2) {
                answer = "NO\n";
            }
        }

        cout << answer;
    }

    return 0;
}