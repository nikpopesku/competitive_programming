#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static vector<int> findSubtreeSizes(vector<int>& parent, const string& s)
    {
        for (int i = 0; i < parent.size(); ++i)
        {
            int current = parent[i];
            while (current != -1 && s[current] != s[i])
            {
                current = parent[current];
            }

            if (s[current] == s[i])
            {
                parent[i] = current;
            }
        }

        return parent;
    }
};


int main()
{
    Solution s;

    vector a = {-1, 0, 0, 1, 1, 1};

    for (const vector response = s.findSubtreeSizes(a, "abaabc"); auto i: response)
    {
        cout << i << " ";
    }
}
