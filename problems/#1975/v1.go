func maxMatrixSum(matrix [][]int) int64 {
    ret, negCnt, minAbsNum := int64(0), 0, math.MaxInt
    for _, row := range matrix {
        for _, num := range row {
            if num < 0 {
                negCnt++
            }
            absNum := abs(num)
            ret += int64(absNum)
            minAbsNum = min(minAbsNum, absNum)
        }
    }
    if negCnt % 2 == 1 {
        ret -= int64(2 * minAbsNum)
    }
    return ret
}

func abs(num int) int {
    if num < 0 {
        return -num
    }
    return num
}