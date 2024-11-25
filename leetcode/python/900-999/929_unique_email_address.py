import sys
from typing import List


class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique = set()
        for email in emails:
            [local_name, domain] = email.split('@')
            local_name = local_name.replace('.', '').split('+')[0]
            unique.add(local_name + '@' + domain)

        return len(unique)


solution = Solution()
print(solution.numUniqueEmails(sys.argv[1:]))