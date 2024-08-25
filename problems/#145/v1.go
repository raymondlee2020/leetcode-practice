/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func postorderTraversal(root *TreeNode) []int {
    ret := make([]int, 0)
    if root == nil {
        return ret
    }
    ret = append(ret, postorderTraversal(root.Left)...)
    ret = append(ret, postorderTraversal(root.Right)...)
    ret = append(ret, root.Val)
    return ret
}