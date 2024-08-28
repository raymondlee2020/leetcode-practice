func countSubIslands(grid1 [][]int, grid2 [][]int) int {
    ret, m, n := 0, len(grid1), len(grid1[0])
    var dfs func(i, j int)
    dfs = func(i, j int) {
        if i < 0 || i == m || j < 0 || j == n || grid2[i][j] == 0 {
            return
        }
        grid2[i][j] = 0
        dfs(i + 1, j)
        dfs(i, j + 1)
        dfs(i - 1, j)
        dfs(i, j - 1)
    }
    for i := range m {
        for j := range n {
            if grid2[i][j] == 1 && grid1[i][j] == 0 {
                dfs(i, j)
            }
        }
    }
    for i := range m {
        for j := range n {
            if grid2[i][j] == 1 {
                dfs(i, j)
                ret++
            }
        }
    }
    return ret
}