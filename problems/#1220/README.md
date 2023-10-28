# Problem 1220 - Count Vowels Permutation

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- State: the ans given first letter i and length j.
- Base cases:
    - dp[i][1] = 1.
- State-transition equation:
    - dp[i][j] = sum(dp[k][j - 1] for k in VALID_FOLLOWED_LETTERS).
