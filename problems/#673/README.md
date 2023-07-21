# Problem 673 - Number of Longest Increasing Subsequence

## V1

Time Complexity: O(n^2)

Space Complexity: O(n)

- State: the max length and cnounter of LIS given last lement at index i.
- Base cases:
    - dp[i] = {1, 1}.
- State-transition equation:
    - dp[i] = {(max length before i) + 1, sum(counter of max length before i)}.
