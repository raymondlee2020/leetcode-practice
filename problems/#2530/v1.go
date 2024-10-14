
type MaxHeap []int

func (m MaxHeap) Len() int {
	return len(m)
}

func (m MaxHeap) Less(i, j int) bool {
	return m[i] > m[j]
}

func (m MaxHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
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

func maxKelements(nums []int, k int) int64 {
    ret, pq := int64(0), MaxHeap{}
    heap.Init(&pq)
    for _, num := range nums {
        heap.Push(&pq, num)
    }
    for ; k > 0; k-- {
        maxnum := heap.Pop(&pq).(int)
        ret += int64(maxnum)
        heap.Push(&pq, int(math.Ceil(float64(maxnum) / 3)))
    }
    return ret
}