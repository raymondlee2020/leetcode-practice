/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func bstToGst(root *TreeNode) *TreeNode {
	solve(root, 0)
	return root
}

func solve(node *TreeNode, acc int) int {
	if node == nil {
		return acc
	}
	node.Val += solve(node.Right, acc)
	return solve(node.Left, node.Val)
}