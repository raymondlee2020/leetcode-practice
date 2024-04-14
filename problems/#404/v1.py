# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        return self.solve(root, False)
    
    def solve(self, node: Optional[TreeNode], isleft: bool) -> int:
        if node == None:
            return 0
        if isleft and node.left == None and node.right == None:
            return node.val
        return self.solve(node.left, True) + self.solve(node.right, False)
        