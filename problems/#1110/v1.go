/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func delNodes(root *TreeNode, toDelete []int) []*TreeNode {
	ret, toDeleteMap := make([]*TreeNode, 0), make(map[int]bool)
	for _, val := range toDelete {
		toDeleteMap[val] = true
	}
	if !toDeleteMap[root.Val] {
		ret = append(ret, root)
	}
	solve(&ret, root, toDeleteMap)
	return ret
}

func solve(ret *[]*TreeNode, node *TreeNode, toDelete map[int]bool) {
	if node.Left != nil {
		solve(ret, node.Left, toDelete)
		if toDelete[node.Val] && !toDelete[node.Left.Val] {
			(*ret) = append(*ret, node.Left)
		}
		if toDelete[node.Left.Val] {
			node.Left = nil
		}
	}
	if node.Right != nil {
		solve(ret, node.Right, toDelete)
		if toDelete[node.Val] && !toDelete[node.Right.Val] {
			(*ret) = append(*ret, node.Right)
		}
		if toDelete[node.Right.Val] {
			node.Right = nil
		}
	}
}