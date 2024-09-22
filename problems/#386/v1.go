func lexicalOrder(n int) []int {
    ret, idx := make([]int, n), 0
    var solve func(i int)
    solve = func(i int) {
        if i > n {
            return
        }
        ret[idx] = i
        idx++
        i *= 10
        for d := range 10 {
            j := i + d
            solve(j)
        }
    }
    for i := 1; i < 10; i++ {
        solve(i)
    }
    return ret
}