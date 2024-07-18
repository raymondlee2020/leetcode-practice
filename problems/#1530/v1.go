/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func countPairs(root *TreeNode, distance int) int {
	ret := 0
	solve(&ret, root, distance)
	return ret
}

func solve(goodPairNum *int, node *TreeNode, distance int) []int {
	ret := make([]int, distance+1)
	if node == nil {
		return ret
	}
	if node.Left == nil && node.Right == nil {
		ret[1] = 1
		return ret
	}
	lret, rret := solve(goodPairNum, node.Left, distance), solve(goodPairNum, node.Right, distance)
	for i := 1; i < distance; i++ {
		for j := 1; j <= distance-i; j++ {
			*goodPairNum += lret[i] * rret[j]
		}
	}
	for i := 1; i < distance; i++ {
		ret[i+1] = lret[i] + rret[i]
	}
	return ret
}