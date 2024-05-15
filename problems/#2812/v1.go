var DIR = []int{0, 1, 0, -1, 0}

type step struct {
	Factor int
	X      int
	Y      int
}

type maxHeap []*step

func (m maxHeap) Len() int {
	return len(m)
}

func (m maxHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m maxHeap) Less(i, j int) bool {
	return m[i].Factor > m[j].Factor
}

func (m *maxHeap) Push(x interface{}) {
	*m = append(*m, x.(*step))
}

func (m *maxHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	old = old[:n-1]
	*m = old
	return x
}

func bfs(grid [][]int) {
	var curr *step
	q, n := make([]*step, 0), len(grid)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				grid[i][j] = 0
				q = append(q, &step{0, i, j})
			} else {
				grid[i][j] = -1
			}
		}
	}
	for len(q) > 0 {
		curr = q[0]
		q = q[1:]
		for i := range 4 {
			nx, ny := curr.X+DIR[i], curr.Y+DIR[i+1]
			if nx < 0 || nx == n || ny < 0 || ny == n || grid[nx][ny] != -1 {
				continue
			}
			grid[nx][ny] = curr.Factor + 1
			q = append(q, &step{grid[nx][ny], nx, ny})
		}
	}
}

func maximumSafenessFactor(grid [][]int) int {
	n := len(grid)
	if grid[0][0] == 1 || grid[n-1][n-1] == 1 {
		return 0
	}
	var ret int
	var curr *step
	bfs(grid)
	pq := &maxHeap{}
	heap.Init(pq)
	heap.Push(pq, &step{grid[0][0], 0, 0})
	grid[0][0] = -1
	for len(*pq) > 0 {
		curr = heap.Pop(pq).(*step)
		if curr.X == n-1 && curr.Y == n-1 {
			ret = curr.Factor
			break
		}
		for i := range 4 {
			nx, ny := curr.X+DIR[i], curr.Y+DIR[i+1]
			if nx < 0 || nx == n || ny < 0 || ny == n || grid[nx][ny] == -1 {
				continue
			}
			heap.Push(pq, &step{min(curr.Factor, grid[nx][ny]), nx, ny})
			grid[nx][ny] = -1
		}
	}
	return ret
}