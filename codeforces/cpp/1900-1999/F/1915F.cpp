#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class FenwickTree {
public:
    explicit FenwickTree(int size) : size_(size), tree_(size + 1, 0) {
    }

    void update(int index, T value) {
        for (++index; index <= size_; index += index & -index) {
            tree_[index] += value;
        }
    }

    T query(int index) {
        T sum = 0;
        for (++index; index > 0; index -= index & -index) {
            sum += tree_[index];
        }
        return sum;
    }

private:
    int size_ = 0;
    vector<T> tree_;
};

struct Interval {
    int start;
    int end;
};

auto solve() {
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    vector<int> end_points;
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].start >> intervals[i].end;
        end_points.push_back(intervals[i].end);
    }

    ranges::sort(end_points);
    end_points.erase(ranges::unique(end_points).begin(), end_points.end());

    for (auto &[start, end]: intervals) {
        end = ranges::lower_bound(end_points, end) - end_points.begin();
    }

    ranges::sort(intervals, [](const auto &a, const auto &b) {
        if (a.start != b.start) {
            return a.start < b.start;
        }
        return a.end > b.end;
    });

    long long inversions = 0;
    FenwickTree<int> ft(n);
    for (int i = 0; i < n; ++i) {
        inversions += ft.query(n - 1) - ft.query(intervals[i].end - 1);
        ft.update(intervals[i].end, 1);
    }

    cout << inversions << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
