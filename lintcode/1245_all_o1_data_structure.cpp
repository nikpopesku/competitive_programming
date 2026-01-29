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
 * - key_to_bucket[key] = iterator to the bucket containing key.
 */
class AllOne {
public:
    void inc(const string &key) {
        if (key_to_bucket_.count(key) == 0) {
            // New key: count becomes 1
            if (buckets_.empty() || buckets_.front().count > 1) {
                buckets_.push_front(Bucket{1, {key}});
            } else {
                buckets_.front().keys.insert(key);
            }
            key_to_bucket_[key] = buckets_.begin();
            return;
        }

        auto it = key_to_bucket_[key];
        int cur = it->count;
        it->keys.erase(key);
        auto nxt = std::next(it);

        if (nxt == buckets_.end() || nxt->count > cur + 1) {
            key_to_bucket_[key] = buckets_.insert(nxt, Bucket{cur + 1, {key}});
        } else {
            nxt->keys.insert(key);
            key_to_bucket_[key] = nxt;
        }

        if (it->keys.empty()) {
            buckets_.erase(it);
        }
    }

    void dec(const string &key) {
        if (key_to_bucket_.count(key) == 0) return;

        auto it = key_to_bucket_[key];
        int cur = it->count;
        it->keys.erase(key);

        if (cur == 1) {
            key_to_bucket_.erase(key);
        } else {
            auto prev = it;
            --prev;
            if (it == buckets_.begin() || prev->count < cur - 1) {
                key_to_bucket_[key] = buckets_.insert(it, Bucket{cur - 1, {key}});
            } else {
                prev->keys.insert(key);
                key_to_bucket_[key] = prev;
            }
        }

        if (it->keys.empty()) {
            buckets_.erase(it);
        }
    }

    string getMaxKey() {
        if (buckets_.empty()) return "";
        return *buckets_.back().keys.begin();
    }

    string getMinKey() {
        if (buckets_.empty()) return "";
        return *buckets_.front().keys.begin();
    }

private:
    struct Bucket {
        int count;
        set<string> keys;
    };
    list<Bucket> buckets_;
    unordered_map<string, list<Bucket>::iterator> key_to_bucket_;
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
