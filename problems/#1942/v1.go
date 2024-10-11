type LeavingHeap [][]int

func (m LeavingHeap) Len() int {
	return len(m)
}

func (m LeavingHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m LeavingHeap) Less(i, j int) bool {
    if m[i][0] == m[j][0] {
        return m[i][1] < m[j][1]
    }
	return m[i][0] < m[j][0]
}

func (m *LeavingHeap) Push(x interface{}) {
	*m = append(*m, x.([]int))
}

func (m *LeavingHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

type SeatHeap []int

func (m SeatHeap) Len() int {
	return len(m)
}

func (m SeatHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m SeatHeap) Less(i, j int) bool {
	return m[i] < m[j]
}

func (m *SeatHeap) Push(x interface{}) {
	*m = append(*m, x.(int))
}

func (m *SeatHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

func smallestChair(times [][]int, targetFriend int) int {
    lpq, spq, n := LeavingHeap{}, SeatHeap{}, len(times)
    heap.Init(&lpq)
    heap.Init(&spq)
    for i := range n {
        times[i] = append(times[i], i)
        heap.Push(&spq, i)
    }
    sort.Slice(times, func(i, j int) bool {
		return times[i][0] < times[j][0]
	})
    var ret int
    for i := range n {
        for len(lpq) > 0 && times[i][0] >= lpq[0][0] {
            heap.Push(&spq, lpq[0][1])
            heap.Pop(&lpq)
        }
        sn := heap.Pop(&spq).(int)
        if times[i][2] == targetFriend {
            ret = sn
            break
        }
        heap.Push(&lpq, []int{times[i][1], sn})
    }
    return ret
}