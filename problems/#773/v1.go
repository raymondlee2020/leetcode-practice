func slidingPuzzle(board [][]int) int {
    boardToString := func(board [][]int) string {
        var sb strings.Builder
        for _, row := range board {
            for _, cell := range row {
                sb.WriteByte(byte(cell) + '0')
            }
        }
        return sb.String()
    }

    ret, tar, cur, q, vis := 0, "123450", boardToString(board), make([]string, 0), make(map[string]bool)
    DIR := []int{-1, 0, 1, 0, -1}
    q = append(q, cur)
    vis[cur] = true
    for len(q) > 0 {
        qs := len(q)
        for _ = range qs {
            cur = q[0]
            q = q[1:]
            if cur == tar {
                return ret
            }
            zidx := strings.Index(cur, "0")
            x, y := zidx / 3, zidx % 3
            for d := range 4 {
                nx, ny := x + DIR[d], y + DIR[d + 1]
                if nx < 0 || nx == 2 || ny < 0 || ny == 3 {
                    continue
                }
                nstate, nidx := []rune(cur), nx * 3 + ny
                nstate[zidx], nstate[nidx] = nstate[nidx], nstate[zidx]
                nxt := string(nstate)
                if !vis[nxt] {
                    vis[nxt] = true
                    q = append(q, nxt)
                }
            }
        }
        ret++
    }
    return -1
}

func boardToString(board [][]int) string {
	var sb strings.Builder
	for _, row := range board {
		for _, cell := range row {
			sb.WriteByte(byte(cell) + '0')
		}
	}
	return sb.String()
}