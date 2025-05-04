#include <format>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;

    const double response = static_cast<double>((100 - A) * A + (100 - B) * B + (100 - C) * C) / static_cast<double>(A +
        B + C);
    cout << format("{}", response) << "\n";
}
