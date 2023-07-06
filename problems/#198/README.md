# Problem 198 - House Robber

## V1

Time Complexity: O(n)

Space Complexity: O(1)

- nums[1] = max(nums[0], nums[1]).
- nums[n] = max(nums[n] + nums[n - 2], nums[n - 1]).
