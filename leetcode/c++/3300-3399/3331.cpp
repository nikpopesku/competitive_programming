#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findSubtreeSizes(const vector<int>& parent, const string& s)
    {
        const int n = static_cast<int>(parent.size());
        vector<vector<int>> children(n);

        // Build adjacency from initial parent info
        for (int i = 1; i < n; ++i)
        {
            children[parent[i]].push_back(i);
        }

        vector ans(n, 0);
        vector<vector<int>> d(26);

        // d[ch] will contain stack of current ancestors whose character is 'a'+ch
        dfs(0, -1, ans, s, children, d);
        return ans;
    }

    void dfs(const int node, const int fa, vector<int>& ans, const string& s, const vector<vector<int>>& children,
             vector<vector<int>>& d)
    {
        ans[node] = 1;
        const int c = s[node] - 'a';
        d[c].push_back(node);

        for (const int ch : children[node])
        {
            dfs(ch, node, ans, s, children, d);
        }

        // The closest ancestor with same char is second last element in d[c];
        // if none, use fa
        int closestAncestorWithSameChar = (d[c].size() > 1) ? d[c][d[c].size() - 2] : fa;

        if (closestAncestorWithSameChar != -1)
        {
            ans[closestAncestorWithSameChar] += ans[node];
        }

        d[c].pop_back();
    };
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
