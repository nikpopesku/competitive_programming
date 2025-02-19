// NOTE: it is recommended to use this even if you don't understand the following code.

#include <cassert>
#include<bits/stdc++.h>

// constraints
#define MAXN 400000

using namespace std;

// input data
int N, K, T, i, t;
vector<int> P;
stack<int> st;

int main() {
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    assert(cin >> T);
    for (t = 0; t < T; t++) {
        assert(cin >> N >> K);
        P.resize(N);
        for (i = 0; i < N; i++) {
            assert(cin >> P[i]);
        }

        for (i = 0; i < N; ++i) {
            if (st.empty() or st.top() != P[i]) {
                st.push(P[i]);
            } else if (st.top() == P[i]) {
                st.pop();
            }
        }

        // write your code here
        cout << (st.empty() ? 1 : 0) << "\n"; // print the result
    }
    return 0;
}
