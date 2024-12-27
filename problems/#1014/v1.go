func maxScoreSightseeingPair(values []int) int {
    ret, n := 0, len(values)
    m1 := values[0]
    for i := 1; i < n; i++ {
        m2 := values[i] - i
        ret = max(ret, m1 + m2)
        m1 = max(m1, values[i] + i)
    }
    return ret
}