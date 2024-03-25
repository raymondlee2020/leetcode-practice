class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        nums.append(0)
        n = len(nums)
        for i in range(n):
            while nums[i] != nums[nums[i]]:
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        return [nums[i] for i in range(n) if i != nums[i]]