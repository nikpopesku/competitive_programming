#include <algorithm>
#include <iostream>
#include <map>
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
        if (mp_string[key] != 0) {
            const int targetValue = mp_string[key];
            auto it = mp_int.find(targetValue);

            while (it != mp_int.end() || it->first == targetValue) {
                if (it->second == key) {
                    mp_int.erase(it);
                    break;
                }

                ++it;
            }
        }

        ++mp_string[key];
        mp_int.insert({mp_string[key], key});
    }

    /**
     * @param key: pop an element from the queue
     * @return: nothing
     */
    void dec(const string &key) {
        const int targetValue = mp_string[key];
        auto it = mp_int.find(targetValue);

        while (it != mp_int.end() || it->first == targetValue) {
            if (it->second == key) {
                mp_int.erase(it);
                break;
            }

            ++it;
        }

        if (mp_string[key] == 1) {
            mp_string.erase(key);
        } else {
            --mp_string[key];
        }

        if (mp_string[key] != 0) {
            mp_int.insert({mp_string[key], key});
        }
    }

    /**
     * @return: nothing
     */
    string getMaxKey() {
        const auto last = mp_int.rbegin();

        return last->second;
    }

    /**
     * @return: nothing
     */
    string getMinKey() {
        const auto first = mp_int.begin();
 return first->second;
    }

private:
    unordered_map<string, int> mp_string;
    multimap<int, string> mp_int;
};


int main() {
    // //["hello","hello"]
    // auto s = AllOne();
    // s.inc("hello");
    // cout << s.getMaxKey() << endl;
    // cout << s.getMinKey() << endl;
    //
    // //["hello","hello","hello","lint"]
    // auto s2 = AllOne();
    // s2.inc("hello");
    // s2.inc("hello");
    // cout << s2.getMaxKey() << endl;
    // cout << s2.getMinKey() << endl;
    // s2.inc("lint");
    // cout << s2.getMaxKey() << endl;
    // cout << s2.getMinKey() << endl;

    //["hello","world","hello","lint","hello"]
    auto s3 = AllOne();
    s3.inc("hello");
    s3.inc("hello");
    s3.inc("world");
    s3.inc("world");
    s3.inc("hello");
    s3.dec("world");
    cout << s3.getMaxKey() << endl;
    cout << s3.getMinKey() << endl;
    s3.inc("world");
    s3.inc("world");
    s3.inc("lint");
    cout << s3.getMaxKey() << endl;
    cout << s3.getMinKey() << endl;
    s3.inc("lint");
    s3.inc("lint");
    cout << s3.getMinKey() << endl;

}
