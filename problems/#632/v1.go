type Item struct {
	num     int
	numIdx  int
	listIdx int
}

type MinHeap []Item

func (m MinHeap) Len() int {
	return len(m)
}

func (m MinHeap) Less(i, j int) bool {
	return m[i].num < m[j].num
}

func (m MinHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m *MinHeap) Push(x interface{}) {
	*m = append(*m, x.(Item))
}

func (m *MinHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

func smallestRange(nums [][]int) []int {
	pq := MinHeap{}
	heap.Init(&pq)
	ret := []int{}
	minRangeLen := math.MaxInt
	maxNum := math.MinInt
	for i, numList := range nums {
		heap.Push(&pq, Item{
			num:       numList[0],
			numIdx:  0,
			listIdx: i,
		})
		maxNum = max(maxNum, numList[0])
	}

	for pq.Len() > 0 {
		cur := heap.Pop(&pq).(Item)
		start := cur.num
		curRangeLen := maxNum - start
		if curRangeLen == 0 {
			ret = []int{start, maxNum}
            break
		}
		if curRangeLen < minRangeLen {
			minRangeLen = curRangeLen
			ret = []int{start, maxNum}
		}
		if cur.numIdx == len(nums[cur.listIdx]) - 1 {
			break
		}
		nxtNumIdx := cur.numIdx + 1
		nxtNum := nums[cur.listIdx][nxtNumIdx]
		heap.Push(&pq, Item{
			num:     nxtNum,
			numIdx:  nxtNumIdx,
			listIdx: cur.listIdx,
		})
		maxNum = max(maxNum, nxtNum)
	}
	return ret
}