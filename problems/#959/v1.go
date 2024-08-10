type tuple struct {
	i int
	j int
	k int
}

func regionsBySlashes(grid []string) int {
	n := len(grid)
	ret, uf := n*n*4, make(map[tuple]tuple)
	for i := range n {
		for j := range n {
			if i > 0 {
				ret = union(ret, &uf, tuple{i - 1, j, 2}, tuple{i, j, 0})
			}
			if j > 0 {
				ret = union(ret, &uf, tuple{i, j - 1, 1}, tuple{i, j, 3})
			}
			if grid[i][j] == '/' {
				ret = union(ret, &uf, tuple{i, j, 0}, tuple{i, j, 3})
				ret = union(ret, &uf, tuple{i, j, 1}, tuple{i, j, 2})
			} else if grid[i][j] == '\\' {
				ret = union(ret, &uf, tuple{i, j, 0}, tuple{i, j, 1})
				ret = union(ret, &uf, tuple{i, j, 2}, tuple{i, j, 3})
			} else {
				ret = union(ret, &uf, tuple{i, j, 0}, tuple{i, j, 1})
				ret = union(ret, &uf, tuple{i, j, 0}, tuple{i, j, 2})
				ret = union(ret, &uf, tuple{i, j, 0}, tuple{i, j, 3})
			}
		}
	}
	return ret
}

func union(cnt int, uf *map[tuple]tuple, i, j tuple) int {
	iroot, jroot := find(uf, i), find(uf, j)
	if iroot == jroot {
		return cnt
	}
	(*uf)[iroot] = jroot
	return cnt - 1
}

func find(uf *map[tuple]tuple, t tuple) tuple {
	parent, exist := (*uf)[t]
	if !exist {
		(*uf)[t] = t
		return t
	}
	if parent == t {
		return t
	}
	root := find(uf, (*uf)[t])
	(*uf)[t] = root
	return root
}