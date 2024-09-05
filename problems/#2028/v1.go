func missingRolls(rolls []int, mean int, n int) []int {
    ret, sum := make([]int, n), mean * (len(rolls) + n)
    for _, roll := range rolls {
        sum -= roll
    }
    if sum > 6 * n || sum < n {
        return []int{}
    }
    sum -= n
    for i := range n {
        if sum > 0 {
            ret[i] = min(sum, 5)
            sum -= 5
        }
        ret[i] += 1 
    }
    return ret
}