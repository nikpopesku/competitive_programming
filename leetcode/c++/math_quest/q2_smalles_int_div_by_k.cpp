#include <iostream>
#include <set>


using namespace std;

#define ll long long

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0) {
            return -1;
        }

        set<ll> uniq;

        ll num = 1;
        int ln = 1;

        while (true) {
            const ll md = num % k;
            if (md == 0) {
                return ln;
            }


            if (uniq.contains(md)) {
                return -1;
            }

            uniq.insert(md);
            num = num * 10;
            num += 1;
            ln += 1;
        }
    }
};

int main() {
    auto s = Solution();

    cout << s.smallestRepunitDivByK(1) << '\n';
    cout << s.smallestRepunitDivByK(2) << '\n';
    cout << s.smallestRepunitDivByK(3) << '\n';
    cout << s.smallestRepunitDivByK(5) << '\n';
}
