type MaxHeap []int

func (m MaxHeap) Len() int {
	return len(m)
}

func (m MaxHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m MaxHeap) Less(i, j int) bool {
	return m[i] > m[j]
}

func (m *MaxHeap) Push(x interface{}) {
	*m = append(*m, x.(int))
}

func (m *MaxHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

func pickGifts(gifts []int, k int) int64 {
    ret, pq := int64(0), &MaxHeap{}
    heap.Init(pq)
    for _, gift := range gifts {
        heap.Push(pq, gift)
    }
    for k > 0 {
        tmp := math.Sqrt(float64(heap.Pop(pq).(int)))
        heap.Push(pq, int(tmp))
        k--
    }
    for len(*pq) > 0 {
        ret += int64(heap.Pop(pq).(int))
    }
    return ret   
}