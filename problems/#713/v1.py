class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:        
        ret, n, l, curr = 0, len(nums), 0, 1
        for r in range(n):
            curr *= nums[r]
            while l <= r and curr >= k:
                ret += r - l
                curr /= nums[l]
                l += 1
        ret += int((n - l + 1) * (n - l) / 2)
        return ret

        