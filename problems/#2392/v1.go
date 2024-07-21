func buildMatrix(k int, rowConditions [][]int, colConditions [][]int) [][]int {
	rowSorted, hasCircle := topologicalSort(k, rowConditions)
	if hasCircle {
		return make([][]int, 0)
	}
	colSorted, hasCircle := topologicalSort(k, colConditions)
	if hasCircle {
		return make([][]int, 0)
	}
	ret := make([][]int, k)
	for i := range k {
		ret[i] = make([]int, k)
	}
	for i := 1; i <= k; i++ {
		ret[rowSorted[i]][colSorted[i]] = i
	}
	return ret
}

func topologicalSort(k int, conds [][]int) ([]int, bool) {
	ret, indegree, childs, q, idx := make([]int, k+1), make([]int, k+1), make([][]int, k+1), make([]int, 0), 0
	for _, cond := range conds {
		childs[cond[0]] = append(childs[cond[0]], cond[1])
		indegree[cond[1]]++
	}
	for i, d := range indegree {
		if i != 0 && d == 0 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		curr := q[0]
		q = q[1:]
		ret[curr] = idx
		idx++
		for _, child := range childs[curr] {
			indegree[child]--
			if indegree[child] == 0 {
				q = append(q, child)
			}
		}
	}
	if idx < k {
		return ret, true
	}
	return ret, false
}
