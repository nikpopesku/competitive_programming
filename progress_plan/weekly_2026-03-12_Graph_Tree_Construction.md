# Week 3: Simple Graph Construction & Trees

## Monday: Learning
- **Technique**: Graph/Tree construction - validity checks, connectivity, topological ordering
- **Tutorial/Link**: Neetcode graph series, LeetCode editorials for topological sort
- **Key Insight**: Union-Find for connectivity/cycle detection; topological sort (Kahn's BFS) for ordering with constraints; BFS/DFS for tree validation

## Wednesday: Practice
- **Problem 1**: [x] Solved - Neetcode: Valid Tree (UF or DFS, exactly n-1 edges + connected)
- **Problem 2**: [x] Solved - Neetcode: Count Connected Components (Union-Find)
- **Problem 3**: [x] Solved - LeetCode 1361 (Validate Binary Tree Nodes) - at most 1 parent per node, single root, no cycles
- **Problem 4**: [x] Solved - LeetCode 2392 (Build Matrix With Conditions) - topological sort on rows and cols independently, then assemble matrix
- **Struggles**: LeetCode 2392 - realizing rows and cols are two independent topological sort problems; cycle detection edge case in 1361

## Thursday: Optimization
- **Found Better Solution**: [x] Yes
- **What I Learned**: Kahn's BFS topological sort is cleaner than DFS for "build in order" problems; Union-Find with path compression handles connectivity checks in near O(1)

## Friday: Competition / Bonus
- **Problem**: [x] Solved - CF "Restore Permutation" (Fenwick Tree / BIT)
  - BIT stores sum of available values; find_first_exceeding walk gives O(log n) value lookup
  - Process right to left, binary-search-style walk in BIT

## Weekend: Free Choice
- **Solved**: AtCoder ABC286-D (Money in Hand) - DP/knapsack
- **Most Interesting**: Fenwick Tree walk trick - avoids O(log²n) binary search

## Not Done / Left To Do
- [ ] Centroid decomposition (advanced tree technique)
- [ ] Heavy-Light Decomposition (HLD)
- [ ] LCA (Lowest Common Ancestor) - binary lifting
- [ ] Tree DP patterns (rerooting technique)
- [ ] Eulerian path / circuit construction on graphs
- [ ] Segment Tree (complement to BIT for range updates)
- [ ] Friday contest session - not attended
- [ ] Weekend free choice problem - only partially explored

## Weekly Reflection
- **What became intuitive**: Union-Find for connectivity, topological sort for dependency-based construction, BIT for order-statistics queries
- **Still confused about**: More advanced tree constructions (centroid decomposition, HLD)
- **Fun level (1-10)**: 9
- **Total Problems Solved**: 5 (4 graph/tree + 1 BIT data structure)
- **Next week focus**: Number Theory Construction (divisibility, GCD/LCM constructions)
