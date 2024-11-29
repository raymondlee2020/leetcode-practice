func shortestDistanceAfterQueries(n int, queries [][]int) []int {
    ret, graph, dis := make([]int, len(queries)), make([][]int, n), make([]int, n)
    for i := 1; i < n; i++ {
        graph[i] = append(graph[i], i - 1)
    }
    for i := range n {
        dis[i] = n - 1 - i
    }
    var dfs func(cur int)
    dfs = func(cur int) {
        newdis := dis[cur] + 1
        for _, adj := range graph[cur] {
            if dis[adj] <= newdis {
                continue
            }
            dis[adj] = newdis
            dfs(adj)
        }
    }
    for i, query := range queries {
        src, dist := query[0], query[1]
        graph[dist] = append(graph[dist], src)
        dis[src] = min(dis[src], dis[dist] + 1)
        dfs(src)
        ret[i] = dis[0]
    }
    return ret
}