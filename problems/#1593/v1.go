func maxUniqueSplit(s string) int {
    ret, exist := 1, make(map[string]bool)
    var solve func(i, acc int)
    solve = func(i, acc int) {
        if i >= len(s) {
            ret = max(ret, acc)
            return
        }
        for j := i + 1; j <= len(s); j++ {
            substr := s[i:j]
            if !exist[substr] {
                exist[substr] = true
                solve(j, acc +1 )
                exist[substr] = false
            }
        }
    }
    solve(0, 0)
    return ret
}