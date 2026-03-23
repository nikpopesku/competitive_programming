#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz): n(sz), tree(sz + 1, 0) {

    }

    void update(int index) {
        ++index;
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }
private:
    int n;
    vector<int> tree;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
}
