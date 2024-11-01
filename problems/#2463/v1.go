func minimumTotalDistance(robot []int, factory [][]int) int64 {
    m, n := len(robot), len(factory)
    sort.Ints(robot)
    sort.Slice(factory, func(i, j int) bool {
        return factory[i][0] < factory[j][0]
    })
    dp := make([][]int64, m + 1)
    for i := range dp {
        dp[i] = make([]int64, n + 1)
        if i < m {
            dp[i][n] = math.MaxInt64
        }
    }
    for j := n - 1; j >= 0; j-- {
        var presum int64
        dq := make([][2]int64, 0)
        dq = append(dq, [2]int64{int64(m), 0})
        for i := m - 1; i >= 0; i-- {
            presum += int64(abs(robot[i] - factory[j][0]))
            if dq[0][0] > int64(i + factory[j][1]) {
                dq = dq[1:]
            }
            curr := dp[i][j + 1] - presum
            for len(dq) > 0 && dq[len(dq) - 1][1] >= curr {
                dq = dq[:len(dq) - 1]
            }
            dq = append(dq, [2]int64{int64(i), curr})
            dp[i][j] = dq[0][1] + presum
        }
    }
    return dp[0][0]
}

func abs(num int) int {
    if num < 0 {
        return -num
    }
    return num
}