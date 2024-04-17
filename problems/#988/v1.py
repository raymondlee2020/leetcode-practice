# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        return self.solve(root, "")

    def solve(self, node: Optional[TreeNode], prefix: str) -> str:
        if node == None:
            return ""
        prefix = chr(node.val + ord('a')) + prefix 
        if node.left == None and node.right == None:
            return prefix
        return self.cmp(self.solve(node.left, prefix), self.solve(node.right, prefix))

    def cmp(self, a: str, b: str) -> str:
        if a == "":
            return b
        if b == "":
            return a
        minlen = min(len(a), len(b))
        for i in range(minlen):
            if a[i] < b[i]:
                return a
            if b[i] < a[i]:
                return b
        return b if len(a) > len(b) else a