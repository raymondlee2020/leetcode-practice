type MinHeap [][]int

func (h MinHeap) Len() int {
	return len(h)
}

func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h MinHeap) Less(i, j int) bool {
    return h[i][0] < h[j][0]
}

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.([]int))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*h = old
	return x
}

func leftmostBuildingQueries(heights []int, queries [][]int) []int {
    ret, qm, pq := make([]int, len(queries)), make([][][]int, len(heights)), &MinHeap{}
    for i := range ret {
        ret[i] = -1
    }
    for i := range qm {
        qm[i] = make([][]int, 0)
    }
    for i, query := range queries {
        a, b := query[0], query[1]
        if a < b {
            a, b = b, a
        }
        if a == b || heights[a] > heights[b] {
            ret[i] = a
        } else {
            qm[a] = append(qm[a], []int{heights[b], i})
        }
    }
    heap.Init(pq)
    for i, height := range heights {
        for len(*pq) > 0 && height > (*pq)[0][0] {
            ret[heap.Pop(pq).([]int)[1]] = i
        }
        for _, q := range qm[i] {
            heap.Push(pq, q)
        }
    }
    return ret
}