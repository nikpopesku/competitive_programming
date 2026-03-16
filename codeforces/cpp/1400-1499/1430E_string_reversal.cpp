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

    int query(int index) const {
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
}
