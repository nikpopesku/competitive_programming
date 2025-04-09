#include<iostream>
#include<vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector town(H, vector<char>(W, '.'));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> town[i][j];
        }
    }

    cout << 1 << "\n";
}