type UnionFind struct {
    Count   int
	Root    map[int]int
}

func (uf *UnionFind) Union(i, j int) {
	iroot, jroot := uf.Find(i), uf.Find(j)
	if iroot == jroot {
		return
	}
	uf.Root[iroot] = jroot
    uf.Count--
}

func (uf *UnionFind) Find(i int) int {
    iroot, exist := uf.Root[i]
    if !exist {
        uf.Root[i] = i
        uf.Count++
    }
	if iroot != i {
		uf.Root[i] = uf.Find(uf.Root[i])
	}
	return uf.Root[i]
}

func removeStones(stones [][]int) int {
    uf := &UnionFind{0, make(map[int]int)}
    for _, stone := range stones {
        stone[1] += 10001
        uf.Union(stone[0], stone[1])
    }
    return len(stones) - uf.Count
}