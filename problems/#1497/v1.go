func canArrange(arr []int, k int) bool {
    cnt := make(map[int]int)
    for _, num := range arr {
        r := num % k
        if r < 0 {
            r += k
        }
        if c, exist := cnt[(k - r) % k]; exist && c > 0 {
            cnt[(k - r) % k]--
        } else {
            cnt[r]++
        }
    }
    for _, c := range cnt {
        if c > 0 {
            return false
        }
    }
    return true
}