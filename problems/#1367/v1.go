/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func isSubPath(head *ListNode, root *TreeNode) bool {
    if root == nil {
        return false
    }
    if head.Val == root.Val && validate(head, root) {
        return true
    }
    return isSubPath(head, root.Left) || isSubPath(head, root.Right)
}

func validate(lc *ListNode, tc *TreeNode) bool {
    if lc == nil {
        return true
    }
    if tc == nil || lc.Val != tc.Val {
        return false
    }
    return validate(lc.Next, tc.Left) || validate(lc.Next, tc.Right)
}