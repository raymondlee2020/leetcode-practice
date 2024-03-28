class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ret, l, n, m = 0, 0, len(nums), {}
        for r in range(0, n):
            if nums[r] not in m:
                m[nums[r]] = 0
            m[nums[r]] += 1
            while m[nums[r]] > k:
                m[nums[l]] -= 1
                l += 1
            ret = max(ret, r - l + 1)
        return ret