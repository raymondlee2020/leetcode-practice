# Problem 2369 - Check if There is a Valid Partition For The Array

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- State: the ans given first i elements in nums.
- Base cases:
    - dp[0] = true.
    - dp[1] = false.
    - dp[2] = nums[0] == nums[1].
- State-transition equation:
    - dp[i] = false.
    - dp[i] |= (nums[i - 1] == nums[i - 2] && dp[i - 2])
    - dp[i] |= (nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3] && dp[i - 3])
    - dp[i] |= (nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1 && dp[i - 3]);
