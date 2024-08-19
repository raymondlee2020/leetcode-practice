# Problem 264 - Ugly Number II

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- State: the ans given n = i.
- Base cases:
    - dp[0] = 1.
- State-transition equation:
    - dp[i] = min(j * dp[MIN_INDEX_HAVENT_MULTIPLY] for j in [2, 3, 5])
