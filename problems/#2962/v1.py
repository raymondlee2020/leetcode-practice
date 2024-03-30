class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ret, n, l, cnt, maxnum = 0, len(nums), 0, 0, max(nums)
        for r in range(n):
            cnt += 1 if nums[r] == maxnum else 0
            while cnt >= k:
                cnt -= 1 if nums[l] == maxnum else 0
                l += 1
            ret += l
        return ret