# Problem 236 - Lowest Common Ancestor of a Binary Tree

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- Recursive solution.
- Stop the traversal and return self when the value is null, p or q.
- When both childs return non-null node, it means the current node is the answer.
- When only one of the childs return non-null node, it means the returned node may be the answer (so return it directly).

## V2

Time Complexity: O(n)

Space Complexity: O(n)

- Iterative solution.
- Build the path set to p by the parent map.
- Tracing back to root from q (with the parent map) until finding the node is in the path set of p.
