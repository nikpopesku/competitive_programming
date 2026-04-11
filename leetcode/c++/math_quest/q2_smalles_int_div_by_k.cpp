#include <iostream>
#include <set>


using namespace std;

#define ll long long

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        set<ll> uniq;

        ll num = 1;

        while (true) {
            int md = num % k;
            if (md == 0) {
                return num;
            }


            if (uniq.contains(md)) {
                return -1;
            }

            uniq.insert(md);
            num = num << 1;
            num += 1;
        }
    }
};

int main() {
    auto s = Solution();

    cout << s.smallestRepunitDivByK(1) << '\n';
    cout << s.smallestRepunitDivByK(2) << '\n';
    cout << s.smallestRepunitDivByK(3) << '\n';
}
