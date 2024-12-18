type MaxHeap [][]int

func (h MaxHeap) Len() int {
	return len(h)
}

func (h MaxHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h MaxHeap) Less(i, j int) bool {
    return h[i][0] > h[j][0]
}

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.([]int))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*h = old
	return x
}

func finalPrices(prices []int) []int {
    pq := &MaxHeap{}
    heap.Init(pq)
    for i, price := range prices {
        for len(*pq) > 0 && price <= (*pq)[0][0] {
            tmp := heap.Pop(pq).([]int)
            prices[tmp[1]] = tmp[0] - price
        }
        heap.Push(pq, []int{price, i})
    }
    return prices
}