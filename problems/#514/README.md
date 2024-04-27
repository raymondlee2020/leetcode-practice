# Problem 514 - Freedom Trail

## V1

Time Complexity: O(n * m)

Space Complexity: O(n * m)

- State: the ans start at i idx in ring to spell key[j:].
- State-transition equation:
    - dp[i][j] = min(dp[idx][j + 1] + (dist between i and idx) for idx in (idxes of key[j])).
