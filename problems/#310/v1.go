func findMinHeightTrees(n int, edges [][]int) []int {
	ret := []int{}
	if n < 3 {
		for i := range n {
			ret = append(ret, i)
		}
		return ret
	}
	degree, graph, q := make([]int, n, n), make([][]int, n, n), []int{}
	for _, edge := range edges {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
		graph[edge[1]] = append(graph[edge[1]], edge[0])
		degree[edge[0]]++
		degree[edge[1]]++
	}
	for i, d := range degree {
		if d == 1 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		qs := len(q)
		ret = make([]int, qs, qs)
		for i := range qs {
			curr := q[0]
			q = q[1:]
			ret[i] = curr
			for _, adj := range graph[curr] {
				degree[adj]--
				if degree[adj] == 1 {
					q = append(q, adj)
				}
			}
		}
	}
	return ret
}