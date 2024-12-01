func checkIfExist(arr []int) bool {
    m := make(map[int]bool)
    for _, num := range arr {
        if m[2 * num] || (num % 2 == 0 && m[num / 2]) {
            return true
        }
        m[num] = true
    }
    return false
}