type UnionFind struct {
	Root map[*TreeNode]*TreeNode
}

func (uf *UnionFind) Union(p *TreeNode, c *TreeNode) {
	proot, croot := uf.Find(p), uf.Find(c)
	if proot == croot {
		return
	}
	uf.Root[croot] = proot
}

func (uf *UnionFind) Find(i *TreeNode) *TreeNode {
	if uf.Root[i] != i {
		uf.Root[i] = uf.Find(uf.Root[i])
	}
	return uf.Root[i]
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func createBinaryTree(descriptions [][]int) *TreeNode {
	uf, set := &UnionFind{make(map[*TreeNode]*TreeNode)}, make(map[int]*TreeNode)
	for _, description := range descriptions {
		child, exist := set[description[1]]
		if !exist {
			child = &TreeNode{description[1], nil, nil}
			uf.Root[child] = child
			set[description[1]] = child
		}
		parent, exist := set[description[0]]
		if !exist {
			parent = &TreeNode{description[0], nil, nil}
			uf.Root[parent] = parent
			set[description[0]] = parent
		}
		if description[2] == 1 {
			parent.Left = child
		} else {
			parent.Right = child
		}
		uf.Union(parent, child)
	}
	return uf.Find(set[descriptions[0][0]])
}