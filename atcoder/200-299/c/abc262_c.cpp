#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;

    vector<ll> vc(n);
    ll response = 0, okay_number = 0, intermediate_response = 0;

    for (ll i = 1; i <= n; ++i) {
        cin >> vc[i - 1];

        if (vc[i - 1] == i) {
            okay_number++;
        } else if (vc[vc[i - 1] - 1] == i) {
            response++;
        }
    }


    if (okay_number > 1) {
        intermediate_response = okay_number * (okay_number - 1) / 2;
    }


    response += intermediate_response;

    cout << response << '\n';
}