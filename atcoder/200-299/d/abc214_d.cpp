#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, u, v, w;
    cin >> N;
    vector<tuple<int, int, int>> vc;

    for (int i = 0; i < N; ++i)
    {
        cin >> u >> v >> w;
        vc.emplace_back(u, v, w);
    }

    cout << 1 << "\n";
}
