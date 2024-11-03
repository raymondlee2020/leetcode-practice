func rotateString(s string, goal string) bool {
    if len(s) != len(goal) {
        return false
    }
    for i, c := range s {
        if byte(c) == goal[0] && s[i:] + s[:i] == goal {
            return true
        }
    }
    return false
}