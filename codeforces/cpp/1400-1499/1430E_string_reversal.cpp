#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1) {
    }

    void update(int index) {
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }

    [[nodiscard]] int query(int index) const {
        int sum = 0;

        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }

        return sum;
    }

private:
    int n;
    vector<int> tree;
};

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    string t = s;
    ranges::reverse(t);

    vector<int> p(n);
    Bit bt(n);

    for (char c = 'a'; c <= 'z'; ++c) {
        vector<int> let_s, let_t;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) let_s.push_back(i);
            if (t[i] == c) let_t.push_back(i);
        }

        for (int i = 0; i < static_cast<int>(let_s.size()); ++i) {
            p[let_s[i]] = let_t[i];
        }
    }

    int answer = 0;

    for (int i = 0; i < n; ++i) {
        answer += i - bt.query(p[i]);
        bt.update(p[i]);
    }


    cout <<  answer << '\n';
}
