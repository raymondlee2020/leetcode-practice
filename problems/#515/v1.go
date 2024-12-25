/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func largestValues(root *TreeNode) []int {
    ret, q := make([]int, 0), make([]*TreeNode, 0)
    if root != nil {
        q = append(q, root)
    }
    for len(q) > 0 {
        s, lvlmax := len(q), math.MinInt
        for _ = range s {
            cur := q[0]
            q = q[1:]
            if cur == nil {
                continue
            }
            lvlmax = max(lvlmax, cur.Val)
            if cur.Left != nil {
                q = append(q, cur.Left)
            }
            if cur.Right != nil {
                q = append(q, cur.Right)
            }
        }
        ret = append(ret, lvlmax)
    }
    return ret
}