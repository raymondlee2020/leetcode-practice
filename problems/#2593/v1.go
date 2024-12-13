func findScore(nums []int) int64 {
    ret, tmp, mark := int64(0), make([][]int, len(nums)), make(map[int]bool)
    for i, num := range nums {
        tmp[i] = []int{num, i}
    }
    sort.Slice(tmp, func(i, j int) bool {
        if tmp[i][0] == tmp[j][0] {
            return tmp[i][1] < tmp[j][1]
        }
        return tmp[i][0] < tmp[j][0]
    })
    for _, e := range tmp {
        if mark[e[1]] {
            continue
        }
        ret += int64(e[0])
        mark[e[1]], mark[e[1] - 1], mark[e[1] + 1] = true, true, true
    }
    return ret
}