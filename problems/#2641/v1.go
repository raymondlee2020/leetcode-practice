/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func replaceValueInTree(root *TreeNode) *TreeNode {
    lsums, q := make([]int, 0), make([]*TreeNode, 0)
    q = append(q, root)
    for len(q) > 0 {
        s, sum := len(q), 0
        for _ = range s {
            cur := q[0]
            q = q[1:]
            sum += cur.Val
            if cur.Left != nil {
                q = append(q, cur.Left)
            }
            if cur.Right != nil {
                q = append(q, cur.Right)
            }
        }
        lsums = append(lsums, sum)
    }
    l, n, q := 1, len(lsums), append(q, root)
    root.Val = 0
    for l < n && len(q) > 0 {
        s := len(q)
        for _ = range s {
            cur, lsum := q[0], lsums[l]
            q = q[1:]
            if cur.Left != nil {
                lsum -= cur.Left.Val
            }
            if cur.Right != nil {
                lsum -= cur.Right.Val
            }
            if cur.Left != nil {
                cur.Left.Val = lsum
                q = append(q, cur.Left)
            }
            if cur.Right != nil {
                cur.Right.Val = lsum
                q = append(q, cur.Right)
            }
        }
        l++
    }
    return root
}