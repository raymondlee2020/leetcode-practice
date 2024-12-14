func continuousSubarrays(nums []int) int64 {
    ret, n := int64(0), len(nums)
    minNum, maxNum := nums[0], nums[0]
    for l, r := 0, 0; r < n; r++ {
        if abs(nums[r] - maxNum) <= 2 && abs(nums[r] - minNum) <= 2 {
            ret += int64(r - l + 1)
            minNum, maxNum = min(minNum, nums[r]), max(maxNum, nums[r])
            continue
        }
        minNum, maxNum = nums[r], nums[r]
        for i := r; i >= l; i-- {
            if abs(nums[r] - nums[i]) > 2 {
                l = i + 1
                break
            }
            minNum, maxNum = min(minNum, nums[i]), max(maxNum, nums[i])
        }
        ret += int64(r - l + 1)
    }
    return ret
}

func abs(num int) int {
    if num < 0 {
        return -num
    }
    return num
}