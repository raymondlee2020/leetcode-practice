func arrayRankTransform(arr []int) []int {
    n := len(arr)
    ret, rank, r := make([]int, n), make(map[int]int), 0
    copy(ret, arr)
    sort.Ints(ret)
    for _, num := range ret {
        if _, exist := rank[num]; !exist {
            r++
            rank[num] = r
        }
    }
    for i, num := range arr {
        ret[i] = rank[num]
    }
    return ret
}