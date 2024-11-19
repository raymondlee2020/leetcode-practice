func maximumSubarraySum(nums []int, k int) int64 {
    ret, n := int64(0), len(nums) + 1
    for b, i, presums, prev := 0, 1, make([]int64, n + 1), make(map[int]int); i < n; i++ {
        num := nums[i - 1]
        j, exist := prev[num]
        presums[i] = presums[i - 1] + int64(num)
        if exist {
            b = max(b, j)
        }
        if i - k >= b {
            ret = max(ret, presums[i] - presums[i - k])
        }
        prev[num] = i
    }
    return ret
}