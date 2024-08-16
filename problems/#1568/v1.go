func minDays(grid [][]int) int {
	DIR, m, n := []int{1, 0, -1, 0, 1}, len(grid), len(grid[0])
	discov, lowestReach, time, landCnt, islandCnt, hasArtPoint := make([][]int, m), make([][]int, m), 0, 0, 0, false
	for i := range m {
		discov[i], lowestReach[i] = make([]int, n), make([]int, n)
	}

	isValidCoord := func(i, j int) bool {
		return i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 1
	}
	var dfs func(i, j, pi, pj int)
	dfs = func(i, j, pi, pj int) {
		time++
		discov[i][j], lowestReach[i][j] = time, time
		landCnt++
		children := 0
		for d := range 4 {
			ci, cj := i+DIR[d], j+DIR[d+1]
			if !isValidCoord(ci, cj) {
				continue
			}
			if discov[ci][cj] == 0 {
				children++
				dfs(ci, cj, i, j)
				lowestReach[i][j] = min(lowestReach[i][j], lowestReach[ci][cj])
				if lowestReach[ci][cj] >= discov[i][j] && pi != -1 {
					hasArtPoint = true
				}
			} else if (ci != pi || cj != pj) && discov[ci][cj] < discov[i][j] {
				lowestReach[i][j] = min(lowestReach[i][j], discov[ci][cj])
			}
		}
		if pi == -1 && children > 1 {
			hasArtPoint = true
		}
	}
	for i := range m {
		for j := range n {
			if grid[i][j] == 1 && discov[i][j] == 0 {
				islandCnt++
				if islandCnt > 1 {
					return 0
				}
				dfs(i, j, -1, -1)
			}
		}
	}
	if landCnt == 0 {
		return 0
	}
	if landCnt == 1 || hasArtPoint {
		return 1
	}
	return 2
}