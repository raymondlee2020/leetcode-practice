/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getDirections(root *TreeNode, startValue int, destValue int) string {
	startPath, destPath := make([]byte, 0), make([]byte, 0)
	getPath(root, &startPath, startValue)
	getPath(root, &destPath, destValue)
	i := 0
	for len(startPath) > i && len(destPath) > i && startPath[i] == destPath[i] {
		i++
	}
	ret := strings.Repeat("U", len(startPath)-i) + string(destPath[i:])
	return ret
}

func getPath(node *TreeNode, path *[]byte, value int) bool {
	if node == nil {
		return false
	}
	if node.Val == value {
		return true
	}
	*path = append(*path, 'L')
	if getPath(node.Left, path, value) {
		return true
	}
	*path = (*path)[:len(*path)-1]
	*path = append(*path, 'R')
	if getPath(node.Right, path, value) {
		return true
	}
	*path = (*path)[:len(*path)-1]
	return false
}