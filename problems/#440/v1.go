func findKthNumber(n int, k int) int {
    curr := 1
    k--
    for k > 0 {
        cnt := countInRange(curr, n)
        if cnt <= k {
            curr++
        } else {
            curr *= 10
            cnt = 1
        }
        k -= cnt
    }
    return curr
}

func countInRange(prefix, n int) int {
    ret, l, r := 0, prefix, prefix
    for l <= n {
        ret += min(r, n) - l + 1
        l, r = l * 10, r * 10 + 9
    }
    return ret
}