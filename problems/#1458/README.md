# Problem 1458 - Max Dot Product of Two Subsequences

## V1

Time Complexity: O(m * n)

Space Complexity: O(n)

- State: the ans with nums1[:i] and nums2[:j].
- Base cases:
    - dp[j] = INT_MIN.
- State-transition equation:
    - dp[j] = max(nums1[i] * nums2[j], LEFTOP + nums1[i] * nums2[j], LEFT, TOP).
