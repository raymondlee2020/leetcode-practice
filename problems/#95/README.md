# Problem 95 - Unique Binary Search Trees II

## V1

Time Complexity: O(n^2)

Space Complexity: O(n^2)

- State: the ans given i nodes.
- Base cases:
    - dp[0] = [NULL].
- State-transition equation:
    - dp[i]:
        - Root node val = j for j in range(0, i).
        - Left subtree candidates are dp[j - 1].
        - Right subtree candidates are dp[i - j] offset j.
