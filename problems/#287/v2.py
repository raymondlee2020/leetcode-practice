class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        ret = -1
        m = list(0 for _ in range(0, len(nums)))
        for num in nums:
            m[num] += 1
            if m[num] == 2:
                ret = num
                break
        return ret
