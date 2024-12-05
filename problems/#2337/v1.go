func canChange(start string, target string) bool {
    i, n := 0, len(start)
    for j, c := range target {
        if c == '_' {
            continue
        }
        if c == 'L' {
            for i < n && start[i] == '_' {
                i++
            }
            if i == n || start[i] != 'L' || i < j {
                return false
            }
            i++
        } else {
            for i < n && start[i] == '_' {
                i++
            }
            if i == n || start[i] != 'R' || i > j {
                return false
            }
            i++
        }
    }
    for ; i < n; i++ {
        if start[i] != '_' {
            return false
        }
    }
    return true
}