func openLock(deadends []string, target string) int {
	if target == "0000" {
		return 0
	}
	m, q := make(map[string]int), make([]string, 0)
	for _, deadend := range deadends {
		m[deadend] = -1
	}
	if _, exist := m["0000"]; exist {
		return -1
	}
	m["0000"] = 0
	q = append(q, "0000")
	for len(q) > 0 {
		curr := q[0]
		q = q[1:]
		for i := range 4 {
			adj := rotate(curr, i, 1)
			if adj == target {
				return m[curr] + 1
			}
			if _, exist := m[adj]; exist {
				continue
			}
			m[adj] = m[curr] + 1
			q = append(q, adj)
		}
		for i := range 4 {
			adj := rotate(curr, i, -1)
			if adj == target {
				return m[curr] + 1
			}
			if _, exist := m[adj]; exist {
				continue
			}
			m[adj] = m[curr] + 1
			q = append(q, adj)
		}
	}
	return -1
}

func rotate(code string, idx int, dir int) string {
	return code[:idx] + string((int(code[idx]-'0')+10+dir)%10+'0') + code[idx+1:]
}