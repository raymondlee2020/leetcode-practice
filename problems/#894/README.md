# Problem 894 - All Possible Full Binary Trees

## V1

Time Complexity: O(n^2)

Space Complexity: O(n^2)

- State: the all possible full binary tree when having i nodes.
- Base cases:
    - dp[1] = [0].
    - dp[3] = [0, 0, 0].
- State-transition equation:
    - dp[i] = [combination of dp[j] and dp[i - j - 1] for j in range(1, i, 2)].
