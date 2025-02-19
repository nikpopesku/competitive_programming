// NOTE: it is recommended to use this even if you don't understand the following code.

#include <cassert>
#include <iostream>
#include <vector>

// constraints
#define MAXN 400000

using namespace std;

// input data
int N, K, T, i, t;
vector<int> P;

int main() {
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    assert(cin >> T);
    for(t = 0; t < T; t++) {
        assert(cin >> N >> K);
        P.resize(N);
        for(i = 0; i < N; i++) {
            assert(cin >> P[i]);
        }
        // write your code here
        cout << 42 << endl; // print the result
    }
    return 0;
}
