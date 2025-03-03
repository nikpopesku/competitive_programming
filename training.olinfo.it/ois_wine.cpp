// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
long long K;
vector<int> V;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N >> K;
    V.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    // insert your code here
    int S = 42, E = 69;

    // print the result
    cout << S << ' ' << E << endl;
    return 0;
}