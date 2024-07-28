func secondMinimum(n int, edges [][]int, time int, change int) int {
	graph, dist, q := make(map[int][]int), make([][]int, n+1), make([][]int, 0)
	for _, edge := range edges {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
		graph[edge[1]] = append(graph[edge[1]], edge[0])
	}
	for i := range n + 1 {
		dist[i] = []int{math.MaxInt, math.MaxInt}
	}
	dist[1][0] = 0
	q = append(q, []int{1, 0})
	for dist[n][1] == math.MaxInt {
		curr, newdist := q[0], q[0][1]+1
		q = q[1:]
		for _, adj := range graph[curr[0]] {
			if newdist < dist[adj][0] {
				dist[adj][0], dist[adj][1] = newdist, dist[adj][0]
			} else if newdist > dist[adj][0] && newdist < dist[adj][1] {
				dist[adj][1] = newdist
			} else {
				continue
			}
			q = append(q, []int{adj, newdist})
		}
	}
	ret, step := 0, dist[n][1]
	for step > 0 {
		if (ret/change)%2 == 1 {
			ret = change * (ret/change + 1)
		}
		ret += time
		step--
	}
	return ret
}