// Study helper only — same KMP logic as 9_problem_hwk.c, rewritten with
// vector so you can inspect needle_lps and j in a debugger without
// chasing char* pointer arithmetic.
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> buildLps(const vector<char> &needle) {
    vector<int> lps(needle.size(), 0);

    for (size_t i = 1; i < needle.size(); ++i) {
        int j = lps[i - 1];

        while (j > 0 && tolower(needle[i]) != tolower(needle[j])) {
            j = lps[j - 1];
        }

        lps[i] = j + (tolower(needle[i]) == tolower(needle[j]) ? 1 : 0);
    }

    return lps;
}

// Same shape as strstrci: scans starting at `from`, j always starts at 0,
// returns the index of the first match at or after `from`, or -1 if none.
long findNext(const vector<char> &haystack,
              const vector<char> &needle,
              const vector<int> &lps,
              size_t from) {
    if (haystack.size() - from < needle.size()) {
        return -1;
    }

    int j = 0;
    for (size_t i = from; i < haystack.size(); ++i) {

        while (j > 0 && tolower(haystack[i]) != tolower(needle[j])) {
            j = lps[j - 1];
        }

        if (tolower(haystack[i]) == tolower(needle[j])) {
            ++j;
        }

        if (j == static_cast<int>(needle.size())) {
            return static_cast<long>(i - needle.size() + 1);
        }
    }

    return -1;
}

// Mirrors the do-while in main() of 9_problem_hwk.c: call findNext, and on
// each match restart the whole scan one position later.
vector<size_t> kmpSearch(const vector<char> &haystack,
                               const vector<char> &needle,
                               const vector<int> &lps) {
    vector<size_t> matches;
    size_t from = 0;

    while (true) {
        long pos = findNext(haystack, needle, lps, from);
        if (pos == -1) break;

        matches.push_back(static_cast<size_t>(pos));
        from = static_cast<size_t>(pos) + 1;
    }

    return matches;
}

int main() {
    string haystackLine, needleLine;

    cout << "haystack: ";
    getline(cin, haystackLine);
    cout << "needle: ";
    getline(cin, needleLine);

    vector<char> haystack(haystackLine.begin(), haystackLine.end());
    vector<char> needle(needleLine.begin(), needleLine.end());

    vector<int> lps = buildLps(needle);

    cout << "lps: ";
    for (int v : lps) cout << v << ' ';
    cout << '\n';

    vector<size_t> matches = kmpSearch(haystack, needle, lps);

    cout << "count: " << matches.size() << '\n';
    cout << "positions: ";
    for (size_t p : matches) cout << p << ' ';
    cout << '\n';

    return 0;
}