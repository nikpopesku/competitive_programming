#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    vector<int> vc(n);
    long long response = 0, okay_number = 0;

    for (auto i = 1; i <= n; ++i) {
        cin >> vc[i - 1];

        if (vc[i - 1] == i) okay_number++;

        if (vc[i - 1] < i and vc[vc[i - 1] - 1] == i) response++;
    }

    while (okay_number > 1) response *= okay_number--;

    cout << okay_number << '\n';
}