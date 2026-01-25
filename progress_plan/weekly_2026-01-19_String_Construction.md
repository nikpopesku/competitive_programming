# Week 2: String Construction

## Monday: Learning
- **Technique**: String Construction - Palindrome building, pattern matching
- **Tutorial/Link**: LeetCode 1312 editorial, DP for longest palindromic subsequence
- **Key Insight**: Work backwards from desired properties, use DP to find longest palindromic subsequence, then calculate minimum insertions
- **Example**: Minimum insertions to make palindrome (LeetCode 1312) - uses DP with dp[i][j] = 2 + dp[i+1][j-1] when characters match

## Wednesday: Practice
- **Problem 1**: [x] Solved - LeetCode 1312 (Minimum Insertion Steps to Make a String Palindrome)
- **Problem 2**: [x] Solved - LeetCode 214 (Shortest Palindrome)
- **Problem 3**: [x] Solved - LeetCode 767 (Reorganize String)
- **Problem 4**: [x] Solved - LeetCode 1405 (Longest Happy String)
- **Problem 5**: [x] Solved - LeetCode 1400 (Construct K Palindromes)
- **Struggles**: Initially missed setting dp[i][i+1] = 1 for non-matching adjacent characters in length-2 case

## Thursday: Optimization
- **Found Better Solution**: [ ] Yes [ ] No
- **What I Learned**: Bottom-up DP by length is easier than top-down, dp[i][j] = 2 + dp[i+1][j-1] when ends match, answer = n - dp[0][n-1]

## Friday: Competition
- **Contest**: _____________________
- **Used Today's Technique**: [ ] Yes [ ] No
- **Performance**: _____________________

## Weekend: Free Choice
- **Solved**: _____________________
- **Most Interesting**: _____________________

## Lexicographical Optimization (Bonus)
- **Problem 1**: [x] Solved - LeetCode 316 (Remove Duplicate Letters)
- **Problem 2**: [x] Solved - LeetCode 402 (Remove K Digits)
- **Problem 3**: [x] Solved - LeetCode 1081 (Smallest Subsequence of Distinct Characters)
- **Status**: ✅ Completed! Used greedy + stack approach for lexicographically smallest strings

## Weekly Reflection
- **What became intuitive**: Bottom-up DP table filling by length, understanding why dp[i][j] = 2 + dp[i+1][j-1] works, greedy string construction with priority queues
- **Still confused about**: _____________________
- **Fun level (1-10)**: ___
- **Total Problems Solved**: 8 (5 string construction + 3 lexicographical optimization)
- **Next week focus**: Simple Graph Construction (tree building, path lengths, connectivity)
