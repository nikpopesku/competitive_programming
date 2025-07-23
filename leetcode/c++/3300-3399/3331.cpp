#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findSubtreeSizes(const vector<int>& parent, const string& s)
    {
        vector<vector<int>> children(parent.size());

        for (int i = 1; i < parent.size(); ++i)
        {
            children[parent[i]].push_back(i);
        }

        calc(0, -1, s);
    };

    void calc(const int node, int parent, const string& s)
    {
        int c = s[node] - 'a';
    }
};


int main()
{
    Solution s;

    vector a = {-1,0,0,1,1,1};

    for (const vector response = s.findSubtreeSizes(a, "abaabc"); auto i : response)
    {
        cout << i << " ";
    }
}
