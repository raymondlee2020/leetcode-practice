func maxCount(banned []int, n int, maxSum int) int {
    ret, m := 0, make(map[int]bool)
    for _, b := range banned {
        m[b] = true
    }
    for i := 1; i <= n; i++ {
        if m[i] {
            continue
        }
        if maxSum - i < 0 {
            break
        }
        maxSum -= i
        ret++
    }
    return ret
}