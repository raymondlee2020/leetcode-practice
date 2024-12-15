type PassRatioHeap [][]int

func (h PassRatioHeap) Len() int {
	return len(h)
}

func (h PassRatioHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h PassRatioHeap) Less(i, j int) bool {
    return float64(h[i][0] + 1) / float64(h[i][1] + 1) - float64(h[i][0]) / float64(h[i][1]) > float64(h[j][0] + 1) / float64(h[j][1] + 1) - float64(h[j][0]) / float64(h[j][1])
}

func (h *PassRatioHeap) Push(x interface{}) {
	*h = append(*h, x.([]int))
}

func (h *PassRatioHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*h = old
	return x
}

func maxAverageRatio(classes [][]int, extraStudents int) float64 {
    ret, h := float64(0), &PassRatioHeap{}
    heap.Init(h)
    for _, class := range classes {
        heap.Push(h, class)
    }
    for ; extraStudents > 0; extraStudents-- {
        tmp := heap.Pop(h).([]int)
        tmp[0], tmp[1] = tmp[0] + 1, tmp[1] + 1
        heap.Push(h, tmp)
    }
    for _, class := range classes {
        ret += float64(class[0]) / float64(class[1])
    }
    return ret / float64(len(classes))
}