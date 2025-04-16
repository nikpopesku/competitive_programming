#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class DisjointSetUnion
{
public:
    explicit DisjointSetUnion(const int size): size(size, 1), parent(size)
    {
        iota(parent.begin(), parent.end(), 0);
    }

private:
    vector<int> size;
    vector<int> parent;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::cout << n << std::endl;
}
