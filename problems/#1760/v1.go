func minimumSize(nums []int, maxOperations int) int {
    sort.Ints(nums)
    l, r := 1, nums[len(nums) - 1]
    isAvail := func(limit int) bool {
        ops := 0
        for _, num := range nums {
            ops += (num / limit) - 1
            if num % limit != 0 {
                ops++
            }
        }
        return ops <= maxOperations
    }
    for l < r {
        mid := l + (r - l) / 2
        if isAvail(mid) {
            r = mid
        } else {
            l = mid + 1
        }
    }
    return l
}