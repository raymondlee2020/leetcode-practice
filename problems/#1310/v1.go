func xorQueries(arr []int, queries [][]int) []int {
    ret, arr, acc := make([]int, len(queries)), append(arr, 0), 0
    for i := range arr {
        arr[i], acc = acc, acc ^ arr[i]
    }
    for i, query := range queries {
        ret[i] = arr[query[1] + 1] ^ arr[query[0]]
    }
    return ret
}