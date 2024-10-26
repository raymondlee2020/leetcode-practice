type Meta struct {
    Cache int
    LeftHeight int
    RightHeight int
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func treeQueries(root *TreeNode, queries []int) []int {
    m := make(map[int]*Meta)
    var buildMap func(parent, node *TreeNode, height int) int
    buildMap = func(parent, node *TreeNode, height int) int {
        if node == nil {
            return height - 1
        }
        m[node.Val] = &Meta{
            Cache: 0,
            LeftHeight: buildMap(node, node.Left, height + 1),
            RightHeight: buildMap(node, node.Right, height + 1),
        }
        return max(m[node.Val].LeftHeight, m[node.Val].RightHeight)
    }
    rootHeight := buildMap(nil, root, 1) - 1
    var calcHeight func(node *TreeNode, newHeight int)
    calcHeight = func(node *TreeNode, newHeight int) {
        if node == nil {
            return
        }
        m[node.Val].Cache = newHeight
        if m[node.Val].LeftHeight > m[node.Val].RightHeight {
            calcHeight(node.Left, max(m[node.Val].RightHeight, newHeight))
        } else if m[node.Val].RightHeight > m[node.Val].LeftHeight {
            calcHeight(node.Right, max(m[node.Val].LeftHeight, newHeight))
        }
    }
    calcHeight(root, 1)
    for i, val := range queries {
        queries[i] = m[val].Cache
        if m[val].Cache == 0 {
            queries[i] = rootHeight
        } else {
            queries[i]--
        }
    }
    return queries
}