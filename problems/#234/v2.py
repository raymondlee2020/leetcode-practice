# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        return self.solve([head], head)

    def solve(self, curr: list[ListNode], node: Optional[ListNode]) -> bool:
        if node == None:
            return True
        ret = self.solve(curr, node.next)
        if (not ret) or curr[0].val != node.val:
            return False
        curr[0] = curr[0].next
        return True
