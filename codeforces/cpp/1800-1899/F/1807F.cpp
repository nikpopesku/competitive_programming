#include <iostream>
#include <set>

using namespace std;

void solve()
{
    int n, m, i1, j1, i2, j2;
    string current_direction;

    cin >> n >> m >> i1 >> j1 >> i2 >> j2;
    cin >> current_direction;
    set<tuple<int, int, int, int>> visited;

    pair current = {i1, j1};
    pair next_move = {1, -1};

    if (current_direction == "DR")
    {
        next_move = {1, 1};
    }
    else if (current_direction == "UR")
    {
        next_move = {-1, 1};
    }
    else if (current_direction == "UL")
    {
        next_move = {-1, -1};
    }

    int response = 0;


    while (current.first != i2 or current.second != j2)
    {
        if (visited.contains({current.first, current.second, next_move.first, next_move.second}))
        {
            response = -1;
            break;
        }

        visited.insert({current.first, current.second, next_move.first, next_move.second});

        bool hit = false;
        if (current.first == 0 or current.first == n - 1)
        {
            next_move.first = -next_move.first;
            hit = true;
        }

        if (current.second == 0 or current.second == m - 1)
        {
            next_move.second = -next_move.second;
            hit = true;
        }

        if (hit)
        {
            ++response;
        }
        else
        {
            current.first += next_move.first;
            current.second += next_move.second;
        }
    }

    cout << response << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
