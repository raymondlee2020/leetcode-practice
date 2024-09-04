func robotSim(commands []int, obstacles [][]int) int {
    DIR, ret, om := []int{0, 1, 0, -1, 0}, 0, make(map[string]bool)
    x, y, d := 0, 0, 0
    for _, obs := range obstacles {
        om[fmt.Sprintf("%d_%d", obs[0], obs[1])] = true
    }
    for _, cmd := range commands {
        if cmd == -2 {
            d = (d + 4 - 1) % 4
        } else if cmd == -1 {
            d = (d + 4 + 1) % 4
        } else {
            for _ = range cmd {
                x += DIR[d]
                y += DIR[d + 1]
                if om[fmt.Sprintf("%d_%d", x, y)] {
                    x -= DIR[d]
                    y -= DIR[d + 1]
                    break
                }
                ret = max(ret, x * x + y * y)
            }
        }
    }
    return ret
}