func getAncestors(n int, edges [][]int) [][]int {
	ret, tmp, degree, out, q := make([][]int, n), make([]map[int]bool, n), make([]int, n), make([][]int, n), make([]int, 0)
	for _, edge := range edges {
		out[edge[0]] = append(out[edge[0]], edge[1])
		degree[edge[1]]++
	}
	for v, d := range degree {
		tmp[v] = make(map[int]bool)
		if d == 0 {
			q = append(q, v)
		}
	}
	for len(q) > 0 {
		curr := q[0]
		q = q[1:]
		ret[curr] = ancestors(tmp[curr])
		for _, v := range out[curr] {
			tmp[v][curr] = true
			tmp[v] = union(tmp[v], tmp[curr])
			degree[v]--
			if degree[v] == 0 {
				q = append(q, v)
			}
		}
	}
	return ret
}

func ancestors(m map[int]bool) []int {
	ret := make([]int, 0)
	for v, _ := range m {
		ret = append(ret, v)
	}
	sort.Ints(ret)
	return ret
}

func union(s1, s2 map[int]bool) map[int]bool {
	ret := s1
	for k, v := range s2 {
		if v {
			ret[k] = true
		}
	}
	return ret
}