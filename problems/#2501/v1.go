func longestSquareStreak(nums []int) int {
    ret, m := 0, make(map[int]bool)
    for _, num := range nums {
        m[num] = true
    }
    sort.Ints(nums)
    for _, num := range nums {
        if !m[num] {
            continue
        }
        tmp := -1
        for m[num] {
            tmp++
            m[num] = false
            num *= num
        }
        ret = max(ret, tmp)
    }
    if ret == 0 {
        return -1
    }
    return ret + 1
}