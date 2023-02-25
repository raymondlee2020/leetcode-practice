# Problem 684 - Redundant Connection

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- Cycle detection
- Last edge of input having both nodes in cycle.

## V2

Time Complexity: O(n)

Space Complexity: O(n)

- Disjoint Subset Union.
- The edge caused cycle cannot do the union action, due to the two nodes are in the same subset (have the same final parent).
