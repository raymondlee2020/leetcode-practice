# Problem 629 - K Inverse Pairs Array

## V1

Time Complexity: O(n * k ^ 2)

Space Complexity: O(n * k)

- State: the ans given n and k.
- Base cases:
    - dp[i][0] = 1.
- State-transition equation:
    - dp[i][j] = sum(dp[i - 1][l] for l in range(max(j - (i - 1), 0), j)).

## V2

Time Complexity: O(n * k)

Space Complexity: O(n * k)

- dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - i].

## V3

Time Complexity: O(n * k)

Space Complexity: O(k)

- Optimized space.
