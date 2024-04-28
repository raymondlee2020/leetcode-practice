func sumOfDistancesInTree(n int, edges [][]int) []int {
	var calcOneDFS, propDFS func(node int, from int)
	ret, graph, cnt := make([]int, n), make(map[int][]int), make([]int, n)
	for _, edge := range edges {
		i, j := edge[0], edge[1]
		graph[i], graph[j] = append(graph[i], j), append(graph[j], i)
	}
	calcOneDFS = func(node int, from int) {
		cnt[node] = 1
		for _, adj := range graph[node] {
			if adj == from {
				continue
			}
			calcOneDFS(adj, node)
			cnt[node] += cnt[adj]
			ret[node] += ret[adj] + cnt[adj]
		}
	}
	propDFS = func(node int, from int) {
		for _, adj := range graph[node] {
			if adj == from {
				continue
			}
			ret[adj] = ret[node] + (n - cnt[adj]) - cnt[adj]
			propDFS(adj, node)
		}
	}
	calcOneDFS(0, -1)
	propDFS(0, -1)
	return ret
}