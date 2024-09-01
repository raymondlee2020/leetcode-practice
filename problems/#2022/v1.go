func construct2DArray(original []int, m int, n int) [][]int {
    if m * n != len(original) {
        return make([][]int, 0)
    }
    ret := make([][]int, m)
    for i := range m {
        ret[i] = make([]int, n)
        copy(ret[i], original[n * i : n * (i + 1)])
    }
    return ret
}