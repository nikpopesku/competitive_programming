from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p) > len(s):
            return []

        pointer1 = 0
        pointer2 = len(p) - 1
        p_map = {}
        s_map = {}
        response = []

        for i in p:
            p_map[i] = (p_map[i] if i in p_map else 0) + 1

        for i in range(pointer1, pointer2 + 1):
            s_map[s[i]] = (s_map[s[i]] if s[i] in s_map else 0) + 1

        while pointer2 < len(s):
            if p_map == s_map:
                response.append(pointer1)
            s_map[s[pointer1]] -= 1
            if s_map[s[pointer1]] == 0:
                del s_map[s[pointer1]]

            pointer1 += 1
            pointer2 += 1

            if pointer2 < len(s):
                s_map[s[pointer2]] = (s_map[s[pointer2]] if s[pointer2] in s_map else 0) + 1

        return response





solution = Solution()
print(solution.findAnagrams(s = "aaaaaaaaaa", p = "aaaaaaaaaaaaa"))