#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        const set s(v.begin(), v.end());

        backtrack(1, n, s);

        return response;
    }

    int response = 0;
private:
    void backtrack(const int index, const int n, set<int> s) {
        if (s.empty()) {
            ++response;
        }

        for (auto elem: s) {
            if (elem % index == 0 || index % elem == 0) {
                s.erase(elem);
                backtrack(index + 1, n, s);
                s.insert(elem);
            }
        }
    }
};

int main() {
    Solution s;

    int n;
    cin >> n;

    s.countArrangement(n);

    cout << s.response;
}
