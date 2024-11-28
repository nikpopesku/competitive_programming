#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int t;
    int number_cut;
    int earth_height;
    int rope_height;

    vector<int> response;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        number_cut = 0;

        for (int j = 0; j < n; j++) {
            cin >> earth_height >> rope_height;
            if (earth_height > rope_height) {
                number_cut++;
            }
        }

        response.push_back(number_cut);
    }

    for (auto& it : response) {
        cout << it << endl;
    }

    return 0;
}