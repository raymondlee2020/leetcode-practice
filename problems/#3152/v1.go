func isArraySpecial(nums []int, queries [][]int) []bool {
    ret, n, cnt, prev := make([]bool, len(queries)), len(nums), 0, nums[0]
    nums[0] = 0
    for i := 1; i < n; i++ {
        if (nums[i] % 2) == (prev % 2) {
            cnt++
        }
        prev = nums[i]
        nums[i] = cnt
    }
    for i, query := range queries {
        ret[i] = (nums[query[1]] - nums[query[0]]) == 0
    }
    return ret
}