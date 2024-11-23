func rotateTheBox(box [][]byte) [][]byte {
    m, n := len(box), len(box[0])
    ret := make([][]byte, n)
    for i := range n {
        ret[i] = make([]byte, m)
        for j := range m {
            ret[i][j] = '.'
        }
    }
    for i := range m {
        nxto := n - 1
        for j := n - 1; j >= 0; j-- {
            if box[i][j] == '#' {
                ret[nxto][m - 1 - i] = '#'
                nxto--
            } else if box[i][j] == '*' {
                ret[j][m - 1 - i] = '*'
                nxto = j - 1
            }
        }
    }
    return ret
}