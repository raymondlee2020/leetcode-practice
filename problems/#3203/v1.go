func minimumDiameterAfterMerge(edges1 [][]int, edges2 [][]int) int {
    ret, graph, d, cd := 0, make(map[int][]int), 0, 1
    var dfs func(p, c int) int
    dfs = func(p, c int) int {
        md1, md2 := 0, 0
        for _, adj := range graph[c] {
            if adj == p {
                continue
            }
            tmp := dfs(c, adj)
            tmp++
            if tmp > md1 {
                md1, md2 = tmp, md1
            } else if tmp > md2 {
                md2 = tmp
            }
        }
        d = max(d, md1 + md2)
        return md1
    }
    for _, edge := range edges1 {
        graph[edge[0]] = append(graph[edge[0]], edge[1])
        graph[edge[1]] = append(graph[edge[1]], edge[0])
    }
    dfs(-1, 0)
    cd += (d + 1) / 2
    ret = d
    graph, d = make(map[int][]int), 0
    for _, edge := range edges2 {
        graph[edge[0]] = append(graph[edge[0]], edge[1])
        graph[edge[1]] = append(graph[edge[1]], edge[0])
    }
    dfs(-1, 0)
    cd += (d + 1) / 2
    ret = max(ret, d)
    ret = max(ret, cd)
    return ret
}