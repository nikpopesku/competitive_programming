#include <string>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>

using namespace std;

class AllOne {
public:
    /**
     * @param key: the element given to be added
     * @return: nothing
     */
    void inc(const string &key) {
        if (mp.count(key) == 0) {
            if (buckets.begin()->count > 1) {
                buckets.push_front({1, {key}});
            } else {
                buckets.begin()->keys.insert(key);
            }

            mp[key] = buckets.begin();
        } else {
            auto it = mp[key];
            it->keys.erase(key);
            int current = it->count;


            auto nxt = next(it);

            if (nxt == buckets.end() || nxt->count > current + 1) {
                buckets.insert(nxt, {current + 1, {key}});
            } else {
                nxt->keys.insert(key);
            }

            mp[key] = next(it);

            if (it->keys.empty()) {
                buckets.erase(it);
            }
        }
    }

    /**
     * @param key: pop an element from the queue
     * @return: nothing
     */
    void dec(const string &key) {
        if (mp.count(key) == 0) {
            return;
        }

        if (mp[key]->count == 1) {
            buckets.erase(mp[key]);
        } else {
            const auto it = mp[key];
            const int current = it->count;
            auto prev = it;
            --prev;

            it->keys.erase(key);

            if (it == buckets.begin() || prev->count < current - 1) {
                buckets.push_front({current - 1, {key}});

                mp[key] = buckets.begin();
            } else {
                prev->keys.insert(key);
                mp[key] = prev;
            }

            if (it->keys.empty()) {
                buckets.erase(it);
            }
        }
    }

    /**
     * @return: nothing
     */
    string getMaxKey() {
        if (mp.empty()) {
            return "";
        }

        return *buckets.end()->keys.begin();
    }

    /**
     * @return: nothing
     */
    string getMinKey() {
        if (mp.empty()) {
            return "";
        }

        return *buckets.begin()->keys.begin();
    }

private:
    struct Bucket {
        int count;
        set<string> keys;
    };

    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> mp;
};


int main() {
    //["hello","hello"]
    auto s = AllOne();
    s.inc("hello");
    std::cout << s.getMaxKey() << "\n";
    std::cout << s.getMinKey() << "\n";

    //["hello","hello","hello","lint"]
    auto s2 = AllOne();
    s2.inc("hello");
    s2.inc("hello");
    std::cout << s2.getMaxKey() << "\n";
    std::cout << s2.getMinKey() << "\n";
    s2.inc("lint");
    std::cout << s2.getMaxKey() << "\n";
    std::cout << s2.getMinKey() << "\n";

    // //["hello","world","hello","lint","hello"]
    // auto s3 = AllOne();
    // s3.inc("hello");
    // s3.inc("hello");
    // s3.inc("world");
    // s3.inc("world");
    // s3.inc("hello");
    // s3.dec("world");
    // std::cout << s3.getMaxKey() << "\n"; // hello
    // std::cout << s3.getMinKey() << "\n"; // world
    // s3.inc("world");
    // s3.inc("world");
    // s3.inc("lint");
    // std::cout << s3.getMaxKey() << "\n"; // hello (lexicographic among 3)
    // std::cout << s3.getMinKey() << "\n"; // lint
    // s3.inc("lint");
    // s3.inc("lint");
    // std::cout << s3.getMinKey() << "\n"; // hello (all have 3, lexicographic)
}
