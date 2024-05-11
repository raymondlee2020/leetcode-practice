type costPerf struct {
	Val     float64
	Quality float64
}

type minHeap []float64

func (m minHeap) Len() int {
	return len(m)
}

func (m minHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m minHeap) Less(i, j int) bool {
	return m[i] > m[j]
}

func (m *minHeap) Push(x interface{}) {
	*m = append(*m, x.(float64))
}

func (m *minHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

func mincostToHireWorkers(quality []int, wage []int, k int) float64 {
	n, qsum := len(quality), float64(0)
	cands, pq := make([]*costPerf, n), &minHeap{}
	for i := 0; i < n; i++ {
		cands[i] = &costPerf{float64(wage[i]) / float64(quality[i]), float64(quality[i])}
	}
	sort.Slice(cands, func(i, j int) bool {
		return cands[i].Val < cands[j].Val
	})
	heap.Init(pq)
	for i := 0; i < k; i++ {
		qsum += cands[i].Quality
		heap.Push(pq, cands[i].Quality)
	}
	ret := qsum * cands[k-1].Val
	for i := k; i < n; i++ {
		qsum -= heap.Pop(pq).(float64)
		qsum += cands[i].Quality
		heap.Push(pq, cands[i].Quality)
		ret = min(ret, qsum*cands[i].Val)
	}
	return ret
}