/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func balanceBST(root *TreeNode) *TreeNode {
	tmp := make([]int, 0)
	traverse(root, &tmp)
	return build(&tmp, 0, len(tmp)-1)
}

func traverse(node *TreeNode, tmp *[]int) {
	if node == nil {
		return
	}
	traverse(node.Left, tmp)
	*tmp = append(*tmp, node.Val)
	traverse(node.Right, tmp)
}

func build(tmp *[]int, l int, r int) *TreeNode {
	if l > r {
		return nil
	}
	mid := l + (r-l)/2
	return &TreeNode{(*tmp)[mid], build(tmp, l, mid-1), build(tmp, mid+1, r)}
}