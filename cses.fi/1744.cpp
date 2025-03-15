#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int response = 0;

    while (a > 0 and b > 0 and a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
        response += 1;
    }

    cout << response << "\n";
}