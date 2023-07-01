# Problem 2305 - Fair Distribution of Cookies

## V1

Time Complexity: O(k 3^n)

Space Complexity: O(k * 2^n)

- State: the optimal unfairness given i children and cookies mask j.
- Base cases:
    - dp[0][0] = 0.
- State-transition equation:
    - dp[i][j] = max(dp[i - 1][submask] for submask of j).
