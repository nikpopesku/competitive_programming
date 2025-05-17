#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s, p;
        cin >> p;
        cin >> s;

        char cur_p_char = p[0];
        int cur_p_size = 1;
        int s_index = 0;
        string response = "YES";

        for (int i = 1; i < p.size(); ++i)
        {
            if (p[i] == cur_p_char)
            {
                ++cur_p_size;
                continue;
            }

            if (s.size() - s_index < cur_p_size)
            {
                response = "NO";
                break;
            }
            int cur_s_size = 0;

            for (int j = s_index; j < s.size(); ++j)
            {
                if (s[j] == cur_p_char)
                {
                    ++cur_s_size;
                    s_index = j;
                    continue;
                }


                if (cur_s_size < cur_p_size or cur_s_size > cur_p_size * 2)
                {
                    response = "NO";
                }

                break;
            }

            cur_p_char = p[i];
            cur_p_size = 1;

            if (response == "NO") break;
        }

        cout << response << "\n";
    }
}
