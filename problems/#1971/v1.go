type UnionFind struct {
	Count int
	Root  []int
}

func (uf *UnionFind) Init(num int) {
	uf.Root = make([]int, num)
	for i := range num {
		uf.Root[i] = i
	}
	uf.Count = num
}

func (uf *UnionFind) Union(i int, j int) {
	iroot, jroot := uf.Find(i), uf.Find(j)
	if iroot == jroot {
		return
	}
	uf.Root[iroot] = jroot
	uf.Count--
}

func (uf *UnionFind) Find(i int) int {
	if uf.Root[i] != i {
		uf.Root[i] = uf.Find(uf.Root[i])
	}
	return uf.Root[i]

}

func validPath(n int, edges [][]int, source int, destination int) bool {
	uf := new(UnionFind)
	uf.Init(n)
	for _, edge := range edges {
		uf.Union(edge[0], edge[1])
	}
	return uf.Find(source) == uf.Find(destination)
}