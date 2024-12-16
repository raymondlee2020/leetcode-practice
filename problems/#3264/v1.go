type MinHeap [][]int

func (h MinHeap) Len() int {
	return len(h)
}

func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h MinHeap) Less(i, j int) bool {
    if h[i][0] == h[j][0] {
        return h[i][1] < h[j][1]
    }
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

func getFinalState(nums []int, k int, multiplier int) []int {
    pq := &MinHeap{}
    heap.Init(pq)
    for i, num := range nums {
        heap.Push(pq, []int{num, i})
    }
    for ; k > 0; k-- {
        tmp := heap.Pop(pq).([]int)
        nums[tmp[1]] *= multiplier
        tmp[0] = nums[tmp[1]]
        heap.Push(pq, tmp)
    }
    return nums
}