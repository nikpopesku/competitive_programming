from typing import Optional
from listnode import ListNode, create_single_linked_list

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        map = {}
        map_set = set()

        for i in range(len(s)):
            if s[i] not in map:
                if t[i] in map_set:
                    return False
                map[s[i]] = t[i]
                map_set.add(t[i])
            elif map[s[i]] != t[i]:
                return False

        return True


solution = Solution()
print(solution.isIsomorphic(s = "egg", t = "add"))