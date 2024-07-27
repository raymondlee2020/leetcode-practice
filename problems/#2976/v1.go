func minimumCost(source string, target string, original []byte, changed []byte, cost []int) int64 {
	ret, mincost, acode, MaxInt := int64(0), make([][]int, 26), int('a'), int(2*1e6+1)
	for i := range 26 {
		mincost[i] = make([]int, 26)
		for j := range 26 {
			mincost[i][j] = MaxInt
		}
		mincost[i][i] = 0
	}
	n := len(original)
	for i := range n {
		ogidx, chidx := int(original[i])-acode, int(changed[i])-acode
		mincost[ogidx][chidx] = min(mincost[ogidx][chidx], cost[i])
	}
	for mid := range 26 {
		for i := range 26 {
			for j := range 26 {
				mincost[i][j] = min(mincost[i][j], mincost[i][mid]+mincost[mid][j])
			}
		}
	}
	n = len(source)
	for i := range n {
		srcidx, taridx := int(source[i])-acode, int(target[i])-acode
		if mincost[srcidx][taridx] == MaxInt {
			return -1
		}
		ret += int64(mincost[srcidx][taridx])
	}
	return ret
}