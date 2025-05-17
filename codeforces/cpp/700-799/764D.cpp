#include <iostream>
#include <string>
#include <vector>
#include <map> // Or array for fixed alphabet size

void solve()
{
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    std::map<char, int> counts; // Using map for flexibility, array<int, 26> is also good
    for (char c : s)
    {
        counts[c]++;
    }

    int total_pairs = 0;
    int odd_count_chars = 0;

    for (auto const& [key, val] : counts)
    {
        total_pairs += val / 2; // Count pairs
        if (val % 2 != 0)
        {
            odd_count_chars++; // Count characters with odd occurrences
        }
    }

    int base_length_per_palindrome = (total_pairs / k) * 2; // Each palindrome gets this many characters from pairs

    const int remaining_pairs = total_pairs % k;

    if (int flexible_chars = remaining_pairs * 2 + odd_count_chars; flexible_chars >= k)
    {
        base_length_per_palindrome++; // If enough flexible characters, each palindrome can get a middle character
    }

    std::cout << base_length_per_palindrome << std::endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
