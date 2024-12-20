/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func reverseOddLevels(root *TreeNode) *TreeNode {
    cur, nxt, lvl := make([]*TreeNode, 0), make([]*TreeNode, 0), 0
    cur = append(cur, root)
    for cur[0].Left != nil {
        for _, node := range cur {
            nxt = append(nxt, node.Left)
            nxt = append(nxt, node.Right)
        }
        lvl++
        if lvl % 2 == 1 {
            for l, r := 0, len(nxt) - 1; l < r; l, r = l + 1, r - 1 {
                nxt[l].Val, nxt[r].Val = nxt[r].Val , nxt[l].Val 
            }
        }
        cur, nxt = nxt, make([]*TreeNode, 0)
    }
    return root
}