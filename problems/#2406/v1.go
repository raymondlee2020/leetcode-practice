
type MinHeap []int

func (m MinHeap) Len() int {
	return len(m)
}

func (m MinHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m MinHeap) Less(i, j int) bool {
	return m[i] < m[j]
}

func (m *MinHeap) Push(x interface{}) {
	*m = append(*m, x.(int))
}

func (m *MinHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

func minGroups(intervals [][]int) int {
    pq := MinHeap{}
    heap.Init(&pq)
    sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
    for _, interval := range intervals {
        if len(pq) > 0 && pq[0] < interval[0] {
            heap.Pop(&pq)
        }
        heap.Push(&pq, interval[1])
    }
    return len(pq)
}