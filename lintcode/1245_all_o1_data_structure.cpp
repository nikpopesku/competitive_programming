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
    auto s = Solution();

    const vector<vector<int> > edges = {{0, 1}, {0, 2}};
    cout << s.countComponents(3, edges) << endl; //1

    const vector<vector<int> > edges2 = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
    cout << s.countComponents(6, edges2) << endl; //2
}
