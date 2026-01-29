#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class AllOne {
public:
    /**
     * @param key: the element given to be added
     * @return: nothing
     */
    void inc(const string &key) {
        ++mp[key];
    }

    /**
     * @param key: pop an element from the queue
     * @return: nothing
     */
    void dec(const string &key) {
        if (mp[key] == 1) {
            mp.erase(key);
        } else {
            --mp[key];
        }
    }

    /**
     * @return: nothing
     */
    string getMaxKey() {
        // write your code here
    }

    /**
     * @return: nothing
     */
    string getMinKey() {
        // write your code here
    }

private:
    unordered_map<string, int> mp;
};


int main() {
    //["hello","hello"]
    auto s = AllOne();
    s.inc("hello");
    cout << s.getMaxKey() << endl;
    cout << s.getMinKey() << endl;

    //["hello","hello","hello","lint"]
    auto s2 = AllOne();
    s2.inc("hello");
    s2.inc("hello");
    cout << s2.getMaxKey() << endl;
    cout << s2.getMinKey() << endl;
    s2.inc("lint");
    cout << s2.getMaxKey() << endl;
    cout << s2.getMinKey() << endl;
}
