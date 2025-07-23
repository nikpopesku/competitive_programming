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

        vector answer(parent.size(), 0);
        vector<vector<int>> stack(26);

        dfs(0, -1, s, children, answer, stack);

        return answer;
    };

    void dfs(const int node, int parent, const string& s, vector<vector<int>>& children, vector<int>& answer, vector<vector<int>>& stack)
    {
        const int c = s[node] - 'a';
        stack[c].push_back(node);
        answer[node] += 1;

        for (const auto child : children[node])
        {
            dfs(child, node, s, children, answer, stack);
        }

        int nearestCommonAncestor = stack[c].size() > 1 ? stack[c][stack[c].size() - 2] : parent;

        if (nearestCommonAncestor != -1)
        {
            answer[nearestCommonAncestor] += answer[node];
        }

        stack.pop_back();
    }
};


int main()
{
    Solution s;

    vector a = {-1, 0, 0, 1, 1, 1};

    for (const vector response = s.findSubtreeSizes(a, "abaabc"); auto i : response)
    {
        cout << i << " ";
    }
}
