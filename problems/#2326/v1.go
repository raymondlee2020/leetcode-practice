/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func spiralMatrix(m int, n int, head *ListNode) [][]int {
    ret := make([][]int, m)
    for i := range m {
        ret[i] = make([]int, n)
        for j := range n {
            ret[i][j] = -1
        }
    }
    for DIR, d, i, j := []int{0, 1, 0, -1, 0}, 0, 0, 0; head != nil; head= head.Next {
        ret[i][j] = head.Val
        ni, nj := i + DIR[d], j + DIR[d + 1]
        if ni == m || ni < 0 || nj == n || nj < 0 || (ret[i + DIR[d]][j + DIR[d + 1]] != -1) {
            d = (d + 1) % 4
            ni, nj = i + DIR[d], j + DIR[d + 1]
        }
        i, j = ni, nj
    }
    return ret
}