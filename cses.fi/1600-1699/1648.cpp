#include <iostream>
#include <vector>

using namespace std;

class FenWick {
public:
    explicit FenWick(const vector<int>& num): num(num) {
        bit.assign(num.size(), 0);

        for (int i = 0; i < num.size(); ++i) {
            add_delta(bit[i], num[i]);
        }
    }

    void update(const int i, const int value) {
        const int delta = value - num[i];

        num[i] = value;

        add_delta(i, delta);
    }

    int sum_range(const int l, const int r) const {
        return sum(r) - sum(l - 1);
    }

private:
    vector<int> num;
    vector<int> bit;

    void add_delta(int i, const int value) {
        while (i < bit.size()) {
            bit[i] += value;

            i = i | i + 1;
        }
    }

    int sum(int i) const {
        int response = 0;

        while (i >= 0) {
            response += bit[i];

            i = (i & (i + 1)) - 1;
        }

        return response;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q, type, l, r;
    vector<int> v;

    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    auto f = new FenWick(v);

    for (int i = 0; i < q; ++i) {
        cin >> type >> l >> r;

        if (type == 2) {
            cout << f->sum_range(l, r) << "\n";
        } else {
            f->update(k, u);
        }
    }
}