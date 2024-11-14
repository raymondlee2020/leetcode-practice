func countFairPairs(nums []int, lower int, upper int) int64 {
    binarySearch := func(l, r, t int) int {
        for l <= r {
            mid := l + (r - l) / 2
            if nums[mid] >= t {
                r = mid - 1
            } else {
                l = mid + 1
            }
        }
        return r
    }
    sort.Ints(nums)
    ret, n := int64(0), len(nums)
    for i, num := range nums {
        ld, hd := lower - num, upper - num
        ret += int64(binarySearch(nums, i + 1, n - 1, hd + 1) - binarySearch(nums, i + 1, n - 1, low))
    }
    return ret
}