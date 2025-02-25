// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Input data
int N;
vector<int> S;

int main() {
//  Uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    S.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    // Insert your code here

    // Print the result
    cout << 42 << endl;

    return 0;
}