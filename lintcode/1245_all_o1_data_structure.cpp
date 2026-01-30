#include <iterator>
#include <list>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * O(1) AllOne: doubly-linked list of "buckets" (count -> set of keys).
 * - List ordered by count ascending → first bucket = min, last = max.
 * - GetMinKey/GetMaxKey return lexicographically smallest in that bucket (set::begin()).
 * - mp[key] = iterator to the bucket containing key.
 */
class AllOne {
public:
    void inc(const string &key) {
        if (mp.count(key) == 0) {
            // New key: count becomes 1
            if (buckets.empty() || buckets.front().count > 1) {
                buckets.push_front(Bucket{1, {key}});
            } else {
                buckets.front().keys.insert(key);
            }
            mp[key] = buckets.begin();
            return;
        }

        auto it = mp[key];
        int cur = it->count;
        it->keys.erase(key);
        auto nxt = std::next(it);

        if (nxt == buckets.end() || nxt->count > cur + 1) {
            mp[key] = buckets.insert(nxt, Bucket{cur + 1, {key}});
        } else {
            nxt->keys.insert(key);
            mp[key] = nxt;
        }

        if (it->keys.empty()) {
            buckets.erase(it);
        }
    }

    void dec(const string &key) {
        if (mp.count(key) == 0) return;

        auto it = mp[key];
        int cur = it->count;
        it->keys.erase(key);

        if (cur == 1) {
            mp.erase(key);
        } else {
            auto prev = it;
            --prev;
            if (it == buckets.begin() || prev->count < cur - 1) {
                mp[key] = buckets.insert(it, Bucket{cur - 1, {key}});
            } else {
                prev->keys.insert(key);
                mp[key] = prev;
            }
        }

        if (it->keys.empty()) {
            buckets.erase(it);
        }
    }

    string getMaxKey() {
        if (buckets.empty()) return "";
        return *buckets.back().keys.begin();
    }

    string getMinKey() {
        if (buckets.empty()) return "";
        return *buckets.front().keys.begin();
    }

private:
    struct Bucket {
        int count;
        set<string> keys;
    };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> mp;
};

#include <iostream>

int main() {
    // //["hello","hello"]
    // auto s = AllOne();
    // s.inc("hello");
    // std::cout << s.getMaxKey() << "\n";
    // std::cout << s.getMinKey() << "\n";
    //
    // //["hello","hello","hello","lint"]
    // auto s2 = AllOne();
    // s2.inc("hello");
    // s2.inc("hello");
    // std::cout << s2.getMaxKey() << "\n";
    // std::cout << s2.getMinKey() << "\n";
    // s2.inc("lint");
    // std::cout << s2.getMaxKey() << "\n";
    // std::cout << s2.getMinKey() << "\n";

    //["hello","world","hello","lint","hello"]
    auto s3 = AllOne();
    s3.inc("hello");
    s3.inc("hello");
    s3.inc("world");
    s3.inc("world");
    s3.inc("hello");
    s3.dec("world");
    std::cout << s3.getMaxKey() << "\n";  // hello
    std::cout << s3.getMinKey() << "\n";  // world
    s3.inc("world");
    s3.inc("world");
    s3.inc("lint");
    std::cout << s3.getMaxKey() << "\n";  // hello (lexicographic among 3)
    std::cout << s3.getMinKey() << "\n";  // lint
    s3.inc("lint");
    s3.inc("lint");
    std::cout << s3.getMinKey() << "\n";  // hello (all have 3, lexicographic)
}
