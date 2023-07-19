# Problem 96 - Unique Binary Search Trees

## V1

Time Complexity: O(2^n)

Space Complexity: O(2^n)

- State: the amount of BST given unique nums i (bit mask).
- Base cases:
    - dp[0] = 1.
- State-transition equation:
    - dp[i] = dp[high] * dp[low].
- Bit mask.

## V2

Time Complexity: O(n^2)

Space Complexity: O(n)

- State: the amount of BST given the amount i of unique nums.
- Base cases:
    - dp[0] = 1.
- State-transition equation:
    - dp[i] = sum(dp[j - 1] * dp [i - j] for j in rnage(1, i + 1)).

## V1

Time Complexity: O(n^2)

Space Complexity: O(n)

- State: the amount of BST given the amount i of unique nums.
- Base cases:
    - dp[0] = 1.
- State-transition equation:
    - dp[i] = sum(dp[j - 1] * dp [i - j] for j in rnage(1, i + 1)).