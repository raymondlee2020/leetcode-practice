func maximumLength(s string) int {
    l, r := 1, len(s)
    exist := func(num int) bool {
        cnt, p := make([]int, 26), 0
        for i, c := range s {
            c := byte(c)
            if s[p] != c {
                p = i
            }
            if (i - p + 1) >= num {
                cnt[c - 'a']++
            }
            if cnt[c - 'a'] == 3 {
                return true
            }
        }
        return false
    }
    if !exist(1) {
        return -1
    }
    for r - l > 1 {
        mid := l + (r - l) / 2
        if exist(mid) {
            l = mid
        } else {
            r = mid
        }
    }
    return l
}