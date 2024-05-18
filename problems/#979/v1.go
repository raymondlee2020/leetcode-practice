/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func distributeCoins(root *TreeNode) int {
	ret := 0
	solve(&ret, root)
	return ret
}

func solve(moves *int, node *TreeNode) int {
	if node == nil {
		return 0
	}
	leftExcess, rightExcess := solve(moves, node.Left), solve(moves, node.Right)
	totalExcess := node.Val - 1 + leftExcess + rightExcess
	*moves += abs(totalExcess)
	return totalExcess
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}