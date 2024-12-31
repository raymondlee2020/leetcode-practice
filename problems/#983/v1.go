func mincostTickets(days []int, costs []int) int {
    dp := make([]int, 396)
    for _, day := range days {
        dp[day] = 1
    }
    for i := 365; i > 0; i-- {
        if dp[i] == 0 {
            dp[i] = dp[i + 1]
            continue
        }
        dp[i] = min(dp[i + 1] + costs[0], min(dp[i + 7] + costs[1], dp[i + 30] + costs[2]))
    }
    return dp[1]
}