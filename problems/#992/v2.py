class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        ret, lb, l = 0, 0, 0
        m = {}
        for num in nums:
            m[num] = m.get(num, 0) + 1
            if len(m) == k + 1:
                # shift l to decrease len(m) because m[nums[l]] == 1
                del m[nums[l]]
                lb = l = l + 1
            if len(m) == k:
                # check if shift l to next index makes nums[l] run out
                while m[nums[l]] > 1:
                    m[nums[l]] -= 1
                    l += 1
                ret += l - lb + 1
        return ret