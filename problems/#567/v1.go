func checkInclusion(s1 string, s2 string) bool {
    ret, n, m, cnt1, cnt2 := false, len(s1), len(s2), make([]int, 26), make([]int, 26)
    if m < n {
        return false
    }
    for i := range n {
        cnt1[s1[i] - 'a']++
        cnt2[s2[i] - 'a']++
    }
    ret = isEqual(cnt1, cnt2)
    for i := n; !ret && i < m; i++ {
        cnt2[s2[i] - 'a']++
        cnt2[s2[i - n] - 'a']--
        ret = isEqual(cnt1, cnt2)
    }
    return ret
}

func isEqual(a, b []int) bool {
    n := len(a)
    for i := range n {
        if a[i] != b[i] {
            return false
        }
    }
    return true
}