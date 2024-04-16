# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            return TreeNode(val, left = root)
        self.solve(root, val, depth - 2)
        return root

    def solve(self, node: Optional[TreeNode], val: int, depth: int):
        if node == None:
            return
        if depth == 0:
            lsub, rsub = TreeNode(val, left = node.left), TreeNode(val, right = node.right)
            node.left, node.right = lsub, rsub
            return
        depth -= 1
        self.solve(node.left, val, depth)
        self.solve(node.right, val, depth)