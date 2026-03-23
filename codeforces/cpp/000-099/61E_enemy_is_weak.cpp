#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1, 0) {
    }

    void update(int index) {
        ++index;
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }

    [[nodiscard]] int query(int index) const {
        int sum = 0;
        ++index;

        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }

        return sum;
    }

    void clear() {
        for (int i = 0; i <= n; ++i) {
            tree[i] = 0;
        }
    }

private:
    int n;
    vector<int> tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> sorted = v;
    ranges::sort(sorted);
    vector<int> lower(n);
    vector<int> upper(n);

    Bit bt(n);

    for (int i = 0; i < n; ++i) {
        int left = 0, right = n - 1;
        int index = 0;

        while (left < right) {
            index = left + (right - left) / 2;
            if (sorted[index] == v[i]) break;

            if (sorted[index] < v[i]) {
                left = index;
            } else {
                right = index - 1;
            }
        }


        lower[i] = bt.query(index);
        bt.update(index);
    }

    bt.clear();

    for (int i = n - 1; i >= 0; --i) {
        int left = 0, right = n - 1;
        int index = 0;

        while (left < right) {
            index = left + (right - left) / 2;
            if (sorted[index] == v[i]) break;

            if (sorted[index] < v[i]) {
                left = index;
            } else {
                right = index - 1;
            }
        }

        upper[i] = n - bt.query(index);
        bt.update(index);
    }

    long long response = 0;

    for (int i = 0; i < n; ++i) {
        response += lower[i] * upper[i];
    }

    cout << response << '\n';
}
