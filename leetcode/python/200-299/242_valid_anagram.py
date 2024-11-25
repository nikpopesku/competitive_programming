
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hash = {}
        for char in s:
            hash[char] = 1 if char not in hash else hash[char] + 1

        for char in t:
            if char not in hash or hash[char] == 0:
                return False
            else:
                hash[char] -= 1

            if hash[char] == 0:
                del hash[char]

        return True if len(hash) == 0 else False


solution = Solution()
print(solution.isAnagram(s = "ab", t = "ab"))