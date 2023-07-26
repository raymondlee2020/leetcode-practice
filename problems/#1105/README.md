# Problem 1105 - Filling Bookcase Shelves

## V1

Time Complexity: O(w * n)

Space Complexity: O(n)

- State: the min height of shelves with books start with index i.
- Base cases:
    - dp[n] = 0.
- State-transition equation:
    - dp[i] = min(max(height of book[j] for range(i, k)) + dp[k] for k in range(i, n)).
