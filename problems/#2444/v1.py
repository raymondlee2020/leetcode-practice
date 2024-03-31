class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        ret, lb, l, mincnt, maxcnt = 0, 0, 0, 0, 0
        for r, num in enumerate(nums):
            if num < minK or num > maxK:
                mincnt = maxcnt = 0
                lb = l = r + 1
                continue
            mincnt += 1 if num == minK else 0
            maxcnt += 1 if num == maxK else 0
            while mincnt >= 1 and maxcnt >= 1:
                mincnt -= 1 if nums[l] == minK else 0
                maxcnt -= 1 if nums[l] == maxK else 0
                l += 1
            ret += (l - lb)
        return ret
