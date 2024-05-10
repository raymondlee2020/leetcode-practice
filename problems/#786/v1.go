type Fraction struct {
	Val       float64
	NumIndex  int // numerator index
	DenoIndex int // denominator index
}

type minHeap []*Fraction

func (m minHeap) Len() int {
	return len(m)
}

func (m minHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m minHeap) Less(i int, j int) bool {
	return m[i].Val < m[j].Val
}

func (m *minHeap) Push(x interface{}) {
	*m = append(*m, x.(*Fraction))
}

func (m *minHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

func kthSmallestPrimeFraction(arr []int, k int) []int {
	var ret []int
	var curr *Fraction
	n, pq := len(arr), &minHeap{}
	heap.Init(pq)
	for i := 0; i < n-1; i++ {
		heap.Push(pq, &Fraction{float64(arr[i]) / float64(arr[n-1]), i, n - 1})
	}
	for ; k > 0; k-- {
		curr = heap.Pop(pq).(*Fraction)
		heap.Push(pq, &Fraction{float64(arr[curr.NumIndex]) / float64(arr[curr.DenoIndex-1]), curr.NumIndex, curr.DenoIndex - 1})
	}
	ret = []int{arr[curr.NumIndex], arr[curr.DenoIndex]}
	return ret
}