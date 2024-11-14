func minimizedMaximum(n int, quantities []int) int {
    l, r := 1, slices.Max(quantities) + 1
    sort.Ints(quantities)
    canDistribute := func(cand int) bool {
        p := 0
        for _, q := range quantities {
            p += q / cand
            if (q % cand) > 0 {
                p++
            }
        }
        return p <= n
    }
    for l < r {
        mid := l + (r - l) / 2
        if canDistribute(mid) {
            r = mid
        } else {
            l = mid + 1
        }
    }
    return l
}