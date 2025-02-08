#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned int h, w;
    cin >> h >> w;
    vector vc(h, vector<int>(w));

    for (auto i = 0; i < h; i++) {
        for (auto j = 0; j < w; j++) {
            cin >> vc[i][j];
        }
    }

    for (auto j = 0; j < w; j++) {
        for (auto i = 0; i < h; i++) {
            cout << vc[i][j] << (i < h - 1 ? ' ' : '\n');
        }

        cout << endl;
    }
}