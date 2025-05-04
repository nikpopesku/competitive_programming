#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;

    double response = ((100 - A) * A  + (100 - B) * B + (100 - C) * C) / (A + B + C);
    cout << response << "\n";
}
