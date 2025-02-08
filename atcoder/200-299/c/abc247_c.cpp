#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string value = "1";
    for (auto i = 2; i <= n; ++i) value += " " + to_string(i) + " " + value;
    cout << value;
}