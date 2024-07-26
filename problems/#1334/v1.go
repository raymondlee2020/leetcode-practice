func findTheCity(n int, edges [][]int, distanceThreshold int) int {
	ret, mincnt, dist := -1, int(1e4+1), make([][]int, n)
	for i := range n {
		dist[i] = make([]int, n)
		for j := range n {
			dist[i][j] = int(1e4 + 1)
		}
		dist[i][i] = 0
	}
	for _, edge := range edges {
		dist[edge[0]][edge[1]] = edge[2]
		dist[edge[1]][edge[0]] = edge[2]
	}
	for mid := range n {
		for i := range n {
			for j := range n {
				dist[i][j] = min(dist[i][j], dist[i][mid]+dist[mid][j])
			}
		}
	}
	for i := range n {
		currcnt := 0
		for j := range n {
			if dist[i][j] <= distanceThreshold {
				currcnt++
			}
		}
		if currcnt <= mincnt {
			ret, mincnt = i, currcnt
		}
	}
	return ret
}