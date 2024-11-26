func findChampion(n int, edges [][]int) int {
    lrec := make([]int, n)
    for _, edge := range edges {
        if lrec[edge[1]] == 0 {
            lrec[edge[1]] = 1
            n--
        }
    }
    if n > 1 {
        return -1
    }
    var ret int
    for team, hasLosed := range lrec {
        if hasLosed == 0 {
            ret = team
            break
        }
    }
    return ret
}