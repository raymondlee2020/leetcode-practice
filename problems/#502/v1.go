type maxHeap []int

func (m maxHeap) Len() int {
	return len(m)
}

func (m maxHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m maxHeap) Less(i int, j int) bool {
	return m[i] > m[j]
}

func (m *maxHeap) Push(x interface{}) {
	*m = append(*m, x.(int))
}

func (m *maxHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

func findMaximizedCapital(k int, w int, profits []int, capital []int) int {
	n, projects, pv := len(profits), make([][]int, 0), 0
	for i := range n {
		projects = append(projects, []int{capital[i], profits[i]})
	}
	sort.Slice(projects, func(i, j int) bool {
		return projects[i][0] < projects[j][0]
	})
	pq := &maxHeap{}
	heap.Init(pq)
	for ; k > 0; k-- {
		for ; pv < n && w >= projects[pv][0]; pv++ {
			heap.Push(pq, projects[pv][1])
		}
		if len(*pq) == 0 {
			break
		}
		w += heap.Pop(pq).(int)
	}
	return w
}