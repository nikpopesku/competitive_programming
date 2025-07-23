#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static vector<int> findSubtreeSizes(vector<int>& parent, const string& s)
    {
        for (int i = 1; i < parent.size(); ++i)
        {
            int current = parent[i];
            while (current != -1 && s[current] != s[i])
            {
                current = parent[current];
            }

            if (current != -1 && s[current] == s[i])
            {
                parent[i] = current;
            }
        }

        vector size(parent.size(), -1);

        vector<vector<int>> child(parent.size());
        for (int i = 1; i < parent.size(); ++i)
        {
            child[parent[i]].push_back(i);
        }
        getSize(0, child, size);

        return size;
    }

    static int getSize(const int node, vector<vector<int>>& child, vector<int>& size)
    {
        if (size[node] != -1)
        {
            return size[node];
        }

        size[node] = 1;

        for (const auto c : child[node])
        {
            size[node] += getSize(c, child, size);
        }

        return size[node];
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
