#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string value = "1";

    for (auto i = 2; i <= n; ++i) {
        value += to_string(i) + value;
    }

    for (size_t i = 0; i < value.size(); ++i) cout << value[i] << (i < value.size() - 1 ? " " : "\n");
}