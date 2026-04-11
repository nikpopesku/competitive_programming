# Fenwick Tree (BIT): 7-Day Mastery Plan

## Progress Tracker

### Day 1: Understanding BIT Basics (Easy)
**Goal**: Learn the fundamental operations
- [x] LC 307 - Range Sum Query - Mutable
  - Insight: Classic BIT application - point updates, range queries
  - File: `leetcode/c++/300-399/307_range_sum_query_mutable.cpp` ✅ BIT
- [x] LC 315 - Count of Smaller Numbers After Self
  - Insight: Use BIT to count inversions (coordinate compression needed)
  - Technique: Process array from right to left, query for smaller elements
  - File: `leetcode/c++/300-399/315_count_of_smaller_numbers.cpp` ✅ BIT
- [x] CSES 1648 - Dynamic Range Sum Queries
  - Pure BIT template problem
  - File: `cses.fi/1600-1699/1648_dynamic_range_sum_query.cpp` ✅ BIT

**Resources**:
- [TopCoder BIT Tutorial](https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/)
- [CP-Algorithms: Fenwick Tree](https://cp-algorithms.com/data_structures/fenwick.html)

### Day 2: Coordinate Compression (Medium)
**Goal**: Handle large/negative numbers with compression
- [x] LC 493 - Reverse Pairs
  - Insight: Count pairs where nums[i] > 2*nums[j] and i < j
  - Key trick: Multiply by 2 before compression
  - File: `leetcode/c++/400-499/493_reverse_pairs.cpp` ✅ BIT
- [x] LC 1649 - Create Sorted Array through Instructions
  - Insight: Track how many smaller and larger elements exist
  - Technique: Two BIT queries per element
  - File: `leetcode/c++/1600-1699/1649_create_sorted_array_through_inst.cpp` ✅ BIT
- [x] CF 1430E - String Reversal
  - Insight: Count inversions with BIT
  - File: `codeforces/cpp/1400-1499/1430E_string_reversal.cpp` ✅ BIT

### Day 3: 2D Problems (Medium)
**Goal**: Extend BIT to 2D grids
- [x] CSES 1739 - Forest Queries II
  - Insight: 2D BIT for matrix range sums
  - Technique: Nested loops for update and query
  - File: `cses.fi/1700-1799/1739_forest_queries2.cpp` ✅ 2D BIT
- [x] LC 1504 - Count Submatrices With All Ones
  - Insight: Can be solved with BIT for range queries
  - Alternative approach: Stack-based (no BIT needed, but good practice)
  - File: `leetcode/c++/1500-1599/1504_count_submatrices_with_all_ones.cpp` ✅ Stack
- [x] SPOJ MATSUM - Matrix Summation
  - Insight: Classic 2D BIT problem
  - File: `spoj.com/matsum.cpp` ✅ 2D BIT

### Day 4: Order Statistics & Kth Element (Medium)
**Goal**: Find kth smallest/largest element dynamically
**Key Concept**: Binary search on BIT to find kth element
- [x] LC 378 - Kth Smallest Element in a Sorted Matrix
  - Insight: Binary search + BIT for kth element
  - Alternative: Min-heap (easier), but BIT practice is valuable
  - File: `leetcode/c++/300-399/378_kth_smallest_element.cpp` ✅ BIT (with find_kth walk)
- [x] CF 61E - Enemy is Weak
  - Insight: Count inversions in subarrays
  - File: `codeforces/cpp/000-099/61E_enemy_is_weak.cpp` ✅ BIT
- [x] CSES 1649 - Dynamic Range Minimum Queries
  - Note: Requires Segment Tree, not BIT (good to know the difference)
  - File: `cses.fi/1600-1699/1649_dynamic_range_min_query.cpp` ✅ SegTree

### Day 5: Advanced Applications (Medium-Hard)
**Goal**: Combine BIT with other techniques
- [x] LC 327 - Count of Range Sum
  - Insight: Prefix sum + coordinate compression + BIT
  - Key trick: Query for (prefix[j] - upper, prefix[j] - lower)
  - File: `leetcode/c++/300-399/327_count_of_range_sum.cpp` ✅ BIT
- [x] LC 2407 - Longest Increasing Subsequence II
  - Insight: BIT stores max LIS length ending at each value
  - File: `leetcode/c++/2400-2499/2407_longest_increasing_subsequence_ii.cpp` ✅ SegTree
- [x] CF 380C - Sereja and Brackets
  - Insight: BIT with segment tree concepts
  - File: `codeforces/cpp/300-399/380C_sereja_and_brackets.cpp` ✅ SegTree

### Day 6: Range Update, Point Query (Medium-Hard)
**Goal**: Learn difference array technique with BIT
**Key Concept**:
```
Range update [l, r] += val:
  update(l, val)
  update(r+1, -val)
Point query at i:
  query(i) // Returns prefix sum = value at i
```
- [x] CF 276C - Little Girl and Maximum Sum
  - Insight: Range updates with BIT, greedy sorting
  - File: `codeforces/cpp/200-300/276C_little_girl_max_sum_bit.cpp` ✅ BIT
- [x] CSES 1651 - Range Update Queries
  - Insight: Difference array + BIT
  - File: `cses.fi/1600-1699/1651_range_update_queries.cpp` ✅ BIT

### Day 7: Contest Problems (Hard)
**Goal**: Solve challenging BIT problems
- [x] LC 775 - Global and Local Inversions
  - Insight: Mathematical observation + BIT validation
  - Key: Check if all global inversions are local
  - File: `leetcode/c++/700-799/775_global_local_inv_bit.cpp` ✅ BIT
- [x] LC 673 - Number of Longest Increasing Subsequence
  - Insight: Track both length and count using BIT
  - Technique: Coordinate compression + two BIT arrays
  - File: `leetcode/c++/600-699/673_num_longest_increase_subseq.cpp` ✅ BIT
- [ ] CF 1967C - Fenwick Tree
  - Meta problem about BIT!
- [ ] CF 1234D - Distinct Characters Queries
  - Insight: 26 BITs (one per character)
- [ ] SPOJ HORRIBLE - Horrible Queries
  - Insight: Range update, range query (advanced BIT)

---

## Key Patterns Learned

### Pattern 1: Inversion Counting
- Count pairs (i, j) where i < j and arr[i] > arr[j]
- → Process right to left, query smaller elements, update current

### Pattern 2: Dynamic Range Sum
- Frequent updates + frequent queries
- → Direct BIT application

### Pattern 3: Coordinate Compression
- Values in range [1, 10^9] but only n distinct values
- → Map to [0, n-1], use BIT on compressed values

### Pattern 4: BIT Walk (Order Statistics)
- Find kth element using binary search on BIT
- → Walk down the BIT in O(log n) instead of binary search O(log² n)

### Pattern 5: 2D Range Queries
- Matrix with point updates and range sum queries
- → 2D BIT

---

## Status Summary

| Day | Topic                     | Status | Problems Solved                                |
| --- | ------------------------- | ------ | ---------------------------------------------- |
| 1   | BIT Basics                | ✅     | 3/3 (LC 307, LC 315, CSES 1648)               |
| 2   | Coordinate Compression    | ✅     | 3/3 (LC 493, LC 1649, CF 1430E)               |
| 3   | 2D Problems               | ✅     | 3/3 (CSES 1739, LC 1504, SPOJ MATSUM)         |
| 4   | Order Statistics          | ✅     | 3/3 (LC 378, CF 61E, CSES 1649)               |
| 5   | Advanced Applications     | ✅     | 3/3 (LC 327, LC 2407, CF 380C)                |
| 6   | Range Update, Point Query | ✅     | 2/2 (CF 276C, CSES 1651)                       |
| 7   | Contest Problems          | ✅     | 2/5 (LC 775, LC 673)                           |

**Total**: 19/22 problems completed

**Solved with BIT**: LC 307, LC 315, CSES 1648, LC 493, LC 1649, CF 1430E, CSES 1739, SPOJ MATSUM, LC 378, CF 61E, LC 327, CF 276C, CSES 1651, LC 775, LC 673 (15)
**Solved with non-BIT approach**: LC 1504 (stack), CSES 1649 (SegTree), LC 2407 (SegTree), CF 380C (SegTree) (4)
**Remaining**: CF 1967C, CF 1234D, SPOJ HORRIBLE

---

*Created: 2026-04-08*
*Source: Fenwick Tree (BIT): 7-Day Mastery Plan*
