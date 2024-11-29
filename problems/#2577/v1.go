var DIR = []int{0, 1, 0, -1, 0}

type Step struct {
	Time   int
	X      int
	Y      int
}

type MinHeap []*Step

func (m MinHeap) Len() int {
	return len(m)
}

func (m MinHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m MinHeap) Less(i, j int) bool {
	return m[i].Time < m[j].Time
}

func (m *MinHeap) Push(x interface{}) {
	*m = append(*m, x.(*Step))
}

func (m *MinHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

func minimumTime(grid [][]int) int {
    if grid[0][1] > 1 && grid[1][0] > 1 {
        return -1
    }
    var ret int
    m, n, pq := len(grid), len(grid[0]), &MinHeap{}
    heap.Init(pq)
    heap.Push(pq, &Step{0, 0, 0})
    for pq.Len() > 0 {
        cur := heap.Pop(pq).(*Step)
        if cur.X == m - 1 && cur.Y == n - 1 {
            ret = cur.Time
            break
        }
        for i := range 4 {
            nx, ny := cur.X + DIR[i], cur.Y + DIR[i + 1]
            if nx < 0 || nx == m || ny < 0 || ny == n || grid[nx][ny] == -1 {
                continue
            }
            waitTime := 0
            if (grid[nx][ny] - cur.Time) % 2 == 0 {
                waitTime = 1
            }
            nextTime := max(cur.Time + 1, grid[nx][ny] + waitTime)
            heap.Push(pq, &Step{nextTime, nx, ny})
            grid[nx][ny] = -1
        }
    }
    return ret
}