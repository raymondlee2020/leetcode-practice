func maxEqualRowsAfterFlips(matrix [][]int) int {
    ret, cnt := 0, make(map[string]int)
    for _, row := range matrix {
        cur := make([]byte, 0)
        if row[0] == 0 {
            for _, cell := range row {
                cur = append(cur, byte(cell))
            }
        } else {
            for _, cell := range row {
                cur = append(cur, byte(cell ^ 1))
            }
        }
        cnt[string(cur)]++
    }
    for _, v := range cnt {
        ret = max(ret, v)
    }
    return ret
}