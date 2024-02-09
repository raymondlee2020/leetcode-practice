# Problem 368 - Largest Divisible Subset

## V1

Time Complexity: O(n ^ 2)

Space Complexity: O(n)

- State: the lengh of divisible subset starts with index i and its prev index.
- Base cases:
    - dp[i] = {1, i}.
- State-transition equation:
    - dp[i] = max({dp[j][0], j} if nums[j] % nums[i] == 0 else INT_MIN for j in range(i, n)).
